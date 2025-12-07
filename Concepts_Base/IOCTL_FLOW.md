### IOCTL


## Prerequisites
* `copy_to_user` and `copy_from_user` is a Kernel driver API.
* `copy_from_user` handles the page faults and permission checks safely.


## Flow & Basics building block.
* IOCTL is used in `user-space` application.
* When ioctl is called, system performs a context switch from user-mode into kernel-mode.
* Application calls --> glibc wrapper for ioctl --> glibc loads system call ID into a CPU register and executes Hardware instruction to trigger Software interrupt or exceptions.
* svc [supervisor call]instruction. This makes EL0 --> EL1 switch.
* Now an exception is generated here. CPU will go to its vector table to for checking handling function  of this exception.
* Inside driver : We have used `linux/fs.h` --> Inside struct `file_operations` we have `long (*unlocked_ioctl) (struct file *, unsigned int, unsigned long)` function pointer.
* We have registered `my_ioctl` with this func_pointer.
* Now this will be executing : used API inside this function : copy_from_user --> MMU translates user's virtual address to a physical address in RAM.
* Kernel pauses the driver, fetches page from the disk. Updates the static variable value.
* my_ioctl returns 0.
* system_handler restores CPU registers and executes  the instructions to return to the user mode.
* Execution resumes in user-app at the line following the ioctl.


