
## A DRIVER SKELTON
- A Linux driver requires three structural pillars to function.

**The Entry/Exit Points (Lifecycle)**
- The __init and __exit macros that prepare resources when loaded and free them when unloaded.

**The Device Registration (Identity)**
- Obtaining a Major/Minor number (dev_t) so the kernel can identify the device.

**The Operations Structure (Capability)**
- The struct file_operations table. This maps system calls (like open, read, ioctl) from user space to your specific kernel functions.


## MODERN DAY APPROACH

```
static const struct of_device_id my_of_ids[] = {
    { .compatible = "vendor,my-custom-ip" },
    { }
};
MODULE_DEVICE_TABLE(of, my_of_ids);
```
```
static struct platform_driver my_platform_driver = {
    .probe = my_probe_function,   // Init logic moves here
    .remove = my_remove_function, // Exit logic moves here
    .driver = {
        .name = "my_platform_driver",
        .of_match_table = my_of_ids,
    },
};

```