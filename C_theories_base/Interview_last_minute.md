# Bitwise

- First thought should be : How input and output looks! Start solving from there.
- Every bit manipulations happens inside the CPU GPR : which is 4 bytes or 8 bytes in size depending on CPU architecture.
- Think in terms of NIBBLE. 4 bits at a time.

**Mental Model on Bytes**
```bash
One Byte   : 0xFF
Two Byte   : 0xFFFF
Three Byte : 0xFFFFFF
Four Byte  : 0xFFFFFFFF
```

- Negative number representation is also easy to represent and think in HEX.
- MSB bit of a number or byte represents the sign of that byte. If **1** it is **negative**.
- Move to right : Divide by 2. Move to left : Multiply by 2.
```c
n = -128
n >> 1 : (-128)/2^1
n >> 2 : (-128)/2^2
n >> 3 : (-128)/2^3
```

- Arithmetic Shift
    - MSB is preserved and copied to the right.
- Logical Shift
    - MSB is not preserved.

- AND with **1** retains the data.
- OR with **0** retains the data.


## Mental Notes for Problem Solving
```
Think for Masks.
Create mask of 0x1 or 0xFF or 0xF0 or ... similar.
Try to do shifting inplace using MACRO, rather than saving back again to the variable.
Think in terms of AND'ng and shifting.
Think in terms of OR'ng and shifting.
Think in terms of NOR'ng and shifting.
Think of flipping and shifting.
```

# Endianness

- Create a mental model on variable as this fixed data set first and think in terms of that.
```c
int n = 0x87654321;
```
- Start with reasoning of Big endian. MSB byte of variable 'n' will be stored in lower memory address. For example : 0x00

**Big Endian**
```bash
00 04 08 0C
87 65 43 21
```
**Little Endian**
```bash
00 04 08 0C
21 43 65 87
```
- Take a char pointer and assign the address of variable to this char pointer.
- Logic is char pointer will store only 1 byte data and it will store either MSB or LSB at a given point in time. Using this logic, we can reason of a given variable's LSB or MSB stored in char ptr variable.
- Don't forget to **typecaste**

# C
## Compilation Stages

* `Preprocessing`
* `Compilation`
* `Assembling`
* `Linking`

`.c -> .i -> .s -> .o`


## C Storage Class(RACEVS)
* `Register`
* `Auto`
* `Extern`
* `Static`
## Type qualifier
* `volatile`
* `const`
## Operators(RA-LAB)
* `Relational`
* `Arithmetic`
* `Logical`
* `Assignment`
* `Bitwise`


## C Memory Layout

| Segment | Direction / Location | Permissions | Content & Description |
| :--- | :--- | :--- | :--- |
| **Command Line / Env** | High Address | Read / Write | Command line arguments (`argc`, `argv`) and Environment variables (`envp`). |
| **Stack** | Grows Down (↓) | Read / Write | Automatic variables, function parameters, return addresses, and stack frames. Managed automatically by the CPU/Compiler. |
| **Memory Mapping Segment** | Mid (Variable) | Read / Write / Exec | Shared libraries (dynamic linking), `mmap()` allocations, and IPC shared memory. |
| **Heap** | Grows Up (↑) | Read / Write | Dynamic memory allocated via `malloc`, `calloc`, `realloc`. Managed via `brk`/`sbrk` system calls. |
| **BSS** (*Block Started by Symbol*) | Fixed | Read / Write | **Uninitialized** global and static variables. Automatically initialized to zero by the kernel/loader before `main()` executes. |
| **Data** | Fixed | Read / Write | **Initialized** global and static variables (e.g., `static int x = 10;`). |
| **Text (Code / .rodata)** | Low Address | Read / Exec | Binary machine instructions. Usually includes `.rodata` (Read-Only Data) for string literals and constants (e.g., `char *s = "hello";`). |
| **Reserved** | 0x00000000 | No Access | Reserved to catch NULL pointer dereferences. Accessing this generates a SEGFAULT. |


## Difference
```
    char *ptr  = "hello"; --> RO Data, cannot be changed.
    char arr[] = "hello"; --> Local stack Variable, can be changed.
```

## Volatile Keyword or Type Qualifier
```
Tells compiler, value of this variable can change unexpectedly without the knowledge of program's current execution.
Most possibily Hardware can change the state of variable depending on the situation.
```
* `const    (Read-Only)`  : Tells the compiler, "The program code cannot modify this variable."
* `volatile (Changeable)` : Tells the compiler, "This variable may change unexpectedly (outside the program flow), so do not optimize reads/writes.

```bash
const volatile int *ptr;
The value at this address can change due to hardware or interrupts.
The C code (the software) is restricted from writing to it.
```



## C Pointers + Data Types Representation and usage

| Property of Data | Property of Pointer (Variables) | Meaning / Description |
| :--- | :--- | :--- |
| `int` | `* p1;` | pointer to int |
| `int const`<br>`const int` | `* p2;`<br>`* p3;` | int is a constant |
| `int` | `* const p4;` | Pointer is a constant |
| `int const`<br>`const int` | `* volatile p5;`<br>`* volatile p6;` | Data is constant, pointer may change. |
| `int volatile`<br>`volatile int` | `* const p7;`<br>`* const p8;` | Data may change but pointer is constant. |
| `int const`<br>`const int` | `* const p9;`<br>`* const p10;` | Data and Pointer both are constants. |

## Array Arithmetics
