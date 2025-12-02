### DMA 

## Base Reasoning on why DMA is needed
- The `CPU operates at GHz` speeds, while `memory and peripherals` often operate at significantly `lower speeds` or have high latency.
- If the CPU is forced to perform large data transfers like `memcpy`. Results in CPU entering a `busy wait` or high-load state, wasting cycles.

## Derived Reasoning
- We introduce : Specialized hardware unit: the DMA Controller (DMAC) a `Bus Master`.
- Bus master can request `control` of `system bus`.
    `System Bus : AHB, AXI, PCIe`

## Building Blocks
- Fundamental unit of DMA operation is the Transfer Descriptor.(Buffer Descriptor)
- This descriptor is a Data Structure in `Memory`. Shared between CPU and DMAC : defines one transaction.

### Structure of Descriptor

- `Source Address`      : Where data lives [ADC register or memory buffer]
- `Destination Address` : Where data goes in.
- `Transfer count`      : Number of bytes or words to move.
- `Control/Status`      : Configuration.

Configuration       - increment address, interrupt on completion, data width, validity bits

* CPU writes above values into `RAM`.
* DMAC reads this values or this descriptor. Loads it's controller with this data.
* DMAC executes as  per the laoded data and updates to STATUS or CONTROL descriptor for completion.


## Linux Implementation Base Block

### Hardware Sequence Mental Model

- `Request(BREQ/DREQ)`  -> Peripheral[UART RX] asserts hardware line to the DMAC indicating : Data is ready to read(in this case of RX).
- `Bus Arbitration`     -> DMAC asks Bus arbiter for the control of the bus.
- `Bus Granted`         -> Access granted to DMAC. CPU is now put on hold or uses cache.
- `Transfer`            -> DMAC performs the Read/Write based on descriptor.
- `Interrupt`           -> Transfers count reaches 0 on completion. DMAC fires an interrupt to CPU.

```
Bandwidth DMA = (Buswidth x Frequency)/(Cycles per transfer)
```

## Linux Kernel DMA : CHALLENGE OF ADDRESS
- Concept of address is nuanced due to `MMU`.
- `Virtual Address`[VA]     :   This is what the kernel code sees.{void *}
- `Physical Address`[PA]    :   This is what the RAM controller see.
- `Bus Address`[BA]         :   This is what the DMAC sees.

### THE RULE
- CPU uses VA. DMAC cannot use VA, DMAC requires BA.
- In some of embedded systems : PA ~=~ BA.
- If IOMMU is present : PA != BA.
```
    MMU       IOMMU
VA ------>PA-------->BA 
```
- `Linux DMA API` : Handles this above translation.

`Note : Never pass a kmalloc pointer directly to the DMA register`
```
kmalloc --> driver code --> Virtual address ---> DMA register don't want Virtual address --> It wants BA, so after kmalloc translation is needed.
```
[DMA-mapping-header](https://github.com/torvalds/linux/blob/master/include/linux/dma-mapping.h)

### TWO TYPES OF DMA MAPPING IN KERNEL

#### A. Coherent[Consistent] Mapping
* Used for control structures[Descriptors] or circular buffers that are accessed simultaneously by CPU & DMA.
* `Writes by` the CPU are immediately visible to DMA & vice-versa. [`Disables caching`]
* API   : `dma_alloc_coherent(dev, size, &dma_handle, flag)`
        : returns : Kernel `virtual address` for the CPU to use and puts `bus address` into `dma_handle`.

`TODO` : Check more on usage and implementation of this API.

#### B. Streaming Mapping
* Use : One time data buffers[Network packer or file block].
* Performance critical and `allows caching`, `cache maintainance` is a must.
* Buffer is `mapper, transferred & unmapped`.
* API   : `dma_map_single(dev, void *ptr, size_t size, direction)`
        : returns : Bus address.


### CONCEPT OF CACHE COHERENCY
- The `CPU interacts` with the `Cache`, not with `DRAM`.
- The `DMA interacts` directly `with DRAM`.

**Assumption Or Mental Note** : 
* At time T0 seconds        :   cache memory of CPU is loaded with some values from DRAM.
* At time T0 seconds        :   DMA operation is triggered.
* T0 + 2 seconds            :   DMA overwrites DRAM with new values that are important for the system to execute from now onwards, but CPU has older value in cache.
* T0 + 2 seconds            :   CPU is unaware of new values.

***The Solution (Cache Maintenance)***
- Before the DMA starts (for CPU --> Device), `we must Clean (Flush) the cache`: push dirty lines to DRAM.
- Before the CPU reads results (for Device --> CPU), we must Invalidate the cache: `force the CPU to re-fetch fresh data from DRAM`.
- Linux API : `dma_sync_single_for_cpu() or dma_sync_single_for_device()`.


