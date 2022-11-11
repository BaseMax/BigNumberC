# Big Number C (BigNumberC)

The Big Number C library is a C library for arbitrary precision arithmetic. It can be used to perform arithmetic operations on numbers of arbitrary size. It is written in C and is designed to be portable and efficient. You can work with numbers of any size, and the library will automatically allocate memory as needed.

## BigNumber Functions

- `BigNumber* createBigNumber(int size)`: Create a Big Number object
- `void setBigNumber(BigNumber *bn, int *digits, int size)`: Set the Big Number object
- `BigNumber* createAndSetBigNumber(int *digits, int size)`: Create a Big Number object and set it digits
- `void destroyBigNumber(BigNumber *bn)`: Destroy the Big Number object
- `void printBigNumber(BigNumber *bn)`: Print the Big Number object
- `BigNumber* addBigNumbers(BigNumber *bn1, BigNumber *bn2)`: Add two Big Numbers
- `BigNumber* multiplyBigNumbers(BigNumber *bn1, BigNumber *bn2)`: Multiply two Big Numbers
- `BigNumber* copyBigNumber(BigNumber *bn)`: Deep copy a Big Number
- `BigNumber* minusBigNumbers(BigNumber *bn1, BigNumber *bn2)`: Minus two Big Numbers
- `BigNumber* divideBigNumbers(BigNumber *bn1, BigNumber *bn2)`: Divide two Big Numbers
- `BigNumber* remainderBigNumbers(BigNumber *bn1, BigNumber *bn2)`: Remainder two Big Numbers
- `int compareBigNumbers(BigNumber *bn1, BigNumber *bn2)`: Compare two Big Numbers

## BigNumber Header

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *digits;
    int size;
} BigNumber;

/**
 Create a Big Number object
 * 
 * @param size 
 * @return BigNumber* 
 */
BigNumber* createBigNumber(int size)

/**
 Set the Big Number object
 * 
 * @param bn
 * @param digits
 * @param size
 */
void setBigNumber(BigNumber *bn, int *digits, int size)

/**
 Create a Big Number object and set it digits
 * 
 * @param digits
 * @param size
 * @return BigNumber* 
 */
BigNumber* createAndSetBigNumber(int *digits, int size)

/**
 Destroy the Big Number object
 * 
 * @param bn 
 */
void destroyBigNumber(BigNumber *bn)

/**
 Print the Big Number object
 * 
 * @param bn 
 */
void printBigNumber(BigNumber *bn)

/**
 Add two Big Numbers
 * 
 * @param bn1 
 * @param bn2 
 * @return BigNumber* 
 */
BigNumber* addBigNumbers(BigNumber *bn1, BigNumber *bn2)

/**
 Multiply two Big Numbers
 * 
 * @param bn1 
 * @param bn2 
 * @return BigNumber* 
 */
BigNumber* multiplyBigNumbers(BigNumber *bn1, BigNumber *bn2)

/**
 Deep copy a Big Number
 * 
 * @param bn
 * @return BigNumber* 
 */
BigNumber* copyBigNumber(BigNumber *bn)

/**
 Minus two Big Numbers
 * 
 * @param bn1
 * @param bn2
 * @return BigNumber*
 */
BigNumber* minusBigNumbers(BigNumber *bn1, BigNumber *bn2)

/**
 Divide two Big Numbers
 * 
 * @param bn1
 * @param bn2
 * @return BigNumber*
 */
BigNumber* divideBigNumbers(BigNumber *bn1, BigNumber *bn2)

/**
 Remainder two Big Numbers
 * 
 * @param bn1
 * @param bn2
 * @return BigNumber*
 */
BigNumber* remainderBigNumbers(BigNumber *bn1, BigNumber *bn2)

/**
 Compare two Big Numbers
 * 
 * @param bn1
 * @param bn2
 * @return int
 */
int compareBigNumbers(BigNumber *bn1, BigNumber *bn2)
```

## TODO

- [ ] Memory optimization
- [ ] Add more functions
- [ ] Add more tests
- [ ] Add more documentation

© Copyright 2022, Max Base
