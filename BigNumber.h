/*
 * @Name: Big/Huge Number Library
 * @Author: Max Base
 * @Date: 2022-11-01
 * @Repository: https://github.com/BaseMax/BigNumberC
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *digits;
    int size;
} BigNumber;

/**
 * @brief Create a Big Number object
 * 
 * @param size 
 * @return BigNumber* 
 */
BigNumber* createBigNumber(int size);

/**
 * @brief Set the Big Number object
 * 
 * @param bn
 * @param digits
 * @param size
 */
void setBigNumber(BigNumber *bn, int *digits, int size);

/**
 * @brief Create a Big Number object and set it digits
 * 
 * @param digits
 * @param size
 * @return BigNumber* 
 */
BigNumber* createAndSetBigNumber(int *digits, int size);

/**
 * @brief Destroy the Big Number object
 * 
 * @param bn 
 */
void destroyBigNumber(BigNumber *bn);

/**
 * @brief Print the Big Number object
 * 
 * @param bn 
 */
void printBigNumber(BigNumber *bn);

/**
 * @brief Add two Big Numbers
 * 
 * @param bn1 
 * @param bn2 
 * @return BigNumber* 
 */
BigNumber* addBigNumbers(BigNumber *bn1, BigNumber *bn2);

/**
 * @brief Multiply two Big Numbers
 * 
 * @param bn1 
 * @param bn2 
 * @return BigNumber* 
 */
BigNumber* multiplyBigNumbers(BigNumber *bn1, BigNumber *bn2);

/**
 * @brief Deep copy a Big Number
 * 
 * @param bn
 * @return BigNumber* 
 */
BigNumber* copyBigNumber(BigNumber *bn);

/**
 * @brief Minus two Big Numbers
 * 
 * @param bn1
 * @param bn2
 * @return BigNumber*
 */
BigNumber* minusBigNumbers(BigNumber *bn1, BigNumber *bn2);

/**
 * @brief Divide two Big Numbers
 * 
 * @param bn1
 * @param bn2
 * @return BigNumber*
 */
BigNumber* divideBigNumbers(BigNumber *bn1, BigNumber *bn2);

/**
 * @brief Remainder two Big Numbers
 * 
 * @param bn1
 * @param bn2
 * @return BigNumber*
 */
BigNumber* remainderBigNumbers(BigNumber *bn1, BigNumber *bn2);

/**
 * @brief Compare two Big Numbers
 * 
 * @param bn1
 * @param bn2
 * @return int
 */
int compareBigNumbers(BigNumber *bn1, BigNumber *bn2);
