#include <stdio.h>
#include <stdlib.h>

#include "BigNumber.h"

/**
 * @brief Main function
 * 
 * @return int 
 */
int main(int argc, char** argv) {
    // createAndSetBigNumber
    printf("bn1 = createAndSetBigNumber: ");
    int digits1[] = {1, 2, 3, 4, 5};
    BigNumber *bn1 = createAndSetBigNumber(digits1, 5);
    printBigNumber(bn1);
    printf("\n");

    // createBigNumber
    printf("bn2 = createBigNumber: ");
    BigNumber *bn2 = createBigNumber(5);
    printBigNumber(bn2);
    printf("\n");

    // setBigNumber
    printf("bn2 = setBigNumber: ");
    int digits2[] = {1, 2, 3, 4, 5};
    setBigNumber(bn2, digits2, 5);
    printBigNumber(bn2);
    printf("\n");

    // addBigNumbers
    printf("bn3 = addBigNumbers bn1, bn2: ");
    BigNumber *bn3 = addBigNumbers(bn1, bn2);
    printBigNumber(bn3);
    printf("\n");

    // copyBigNumber
    printf("bn4 = copyBigNumber bn1: ");
    BigNumber *bn4 = copyBigNumber(bn1);
    printBigNumber(bn4);
    printf("\n");

    // destroyBigNumber
    // printf("destroyBigNumber bn1: ");
    // destroyBigNumber(bn1);
    // printBigNumber(bn1);
    // printf("\n");

    // multiplyBigNumbers
    printf("bn5 = multiplyBigNumbers bn2, bn3: ");
    BigNumber *bn5 = multiplyBigNumbers(bn2, bn3);
    printBigNumber(bn5);
    printf("\n");
    
    // minusBigNumbers
    printf("bn6 = minusBigNumbers bn5, bn4: ");
    BigNumber *bn6 = minusBigNumbers(bn5, bn4);
    printBigNumber(bn6);
    printf("\n");

    // divideBigNumbers
    printf("bn7 = divideBigNumbers bn5, bn6: ");
    BigNumber *bn7 = divideBigNumbers(bn5, bn6);
    printBigNumber(bn7);
    printf("\n");

    // remainderBigNumbers
    printf("bn8 = remainderBigNumbers bn5, bn6: ");
    BigNumber *bn8 = remainderBigNumbers(bn5, bn6);
    printBigNumber(bn8);
    printf("\n");

    return 0;
}
