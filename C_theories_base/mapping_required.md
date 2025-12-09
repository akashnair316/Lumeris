## Reverse a 64 bit value in ARM64
```bash
uint64_t reverse_64_hardware(uint64_t n) {
    return __builtin_bitreverse64(n); 
    // Compiles directly to 'rbit x0, x0' on ARM64
}
```

## static inline
* `inline` - optimization request to compiler - substitue the function call with actual body of function directly into the call site.[increases size in text segment]
* `static` - only visible within the translation unit.

### Use static inline primarily in Header Files (.h) for the following scenarios:
```c
// In a header file: gpio_driver.h

// BAD: Function call overhead is heavier than the bitwise operation
// void gpio_set_high(uint32_t pin); 

// GOOD: Instant injection of assembly instructions
static inline void gpio_set_high(volatile uint32_t *reg, uint32_t pin_mask) {
    *reg |= pin_mask;
}
```

```c
//Generic bit-twiddling logic that is too complex for a one-line macro but small enough to inline.
static inline uint32_t reverse_bytes(uint32_t val) {
    return ((val >> 24) & 0xFF) | ((val >> 8) & 0xFF00) |
           ((val << 8) & 0xFF0000) | ((val << 24) & 0xFF000000);
}
```

## Macros
```c
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

#define container_of(ptr, type, member) ({          \
    const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
    (type *)( (char *)__mptr - offsetof(type,member) );})
```


# OTHER FILE MAP : TEMPORARY

## Boot Flow
* Boot Flow (BL1 -> BL33).
```bash
BL1: Boot ROM (Immutable root of trust). Loads BL2.
BL2: Trusted Boot Firmware. Loads BL31 (EL3 Runtime) and BL33 (Non-secure bootloader).
BL31: The runtime resident firmware at EL3. Handles PSCI (Power State Coordination Interface) and SMCs.
BL33: U-Boot or UEFI (runs at EL2 or EL1).
```

```bash
EL0: User Applications (Unprivileged).
EL1: OS Kernel (Privileged).
EL2: Hypervisor (Virtualization).
EL3: Secure Monitor / ATF (Root of Trust).
Note: ATF (ARM Trusted Firmware) resides in EL3.
```
