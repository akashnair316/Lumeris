## Bitwise

- First thought should be : How input and output looks! Start solving from there.
- Every bit manipulations happens inside the CPU GPR : which is 4 bytes or 8 bytes in size depending on CPU architecture.
- Think in terms of NIBBLE. 4 bits at a time.

**Mental Model on Bytes**
```
One Byte   : 0xFF
Two Byte   : 0xFFFF
Three Byte : 0xFFFFFF
Four Byte  : 0xFFFFFFFF
```

- Negative number representation is also easy to represent and think in HEX.
- MSB bit of a number or byte represents the sign of that byte. If **1** it is **negative**.
- Move to right : Divide by 2. Move to left : Multiply by 2.
```
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


### Mental Notes for Problem Solving
```
Think for Masks.
Create mask of 0x1 or 0xFF or 0xF0 or ... similar.
Try to do shifting inplace using MACRO, rather than saving back again to the variable.
Think in terms of AND'ng and shifting.
Think in terms of OR'ng and shifting.
Think in terms of NOR'ng and shifting.
Think of flipping and shifting.
```

## Endianness

- Create a mental model on variable as this fixed data set first and think in terms of that.
```
int n = 0x87654321;
```
- Start with reasoning of Big endian. MSB byte of variable 'n' will be stored in lower memory address. For example : 0x00

**Big Endian**
```
00 04 08 0C
87 65 43 21
```
**Little Endian**
```
00 04 08 0C
21 43 65 87
```
- Take a char pointer and assign the address of variable to this char pointer.
- Logic is char pointer will store only 1 byte data and it will store either MSB or LSB at a given point in time. Using this logic, we can reason of a given variable's LSB or MSB stored in char ptr variable.
- Don't forget to **typecaste**

