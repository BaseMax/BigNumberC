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
    int digits1[] = {1, 2, 3, 4, 5};
    BigNumber *bn1 = createAndSetBigNumber(digits1, 5);
    printBigNumber(bn1);

    // createBigNumber
    BigNumber *bn2 = createBigNumber(5);
    printBigNumber(bn2);

    // setBigNumber
    int digits2[] = {1, 2, 3, 4, 5};
    setBigNumber(bn2, digits2, 5);
    printBigNumber(bn2);

    // addBigNumbers
    BigNumber *bn3 = addBigNumbers(bn1, bn2);
    printBigNumber(bn3);

    // copyBigNumber
    BigNumber *bn4 = copyBigNumber(bn1);
    printBigNumber(bn4);

    // destroyBigNumber
    destroyBigNumber(bn1);

    // multiplyBigNumbers
    BigNumber *bn5 = multiplyBigNumbers(bn2, bn3);
    printBigNumber(bn5);
    
    // minusBigNumbers
    BigNumber *bn6 = minusBigNumbers(bn5, bn4);
    printBigNumber(bn6);

    // divideBigNumbers
    BigNumber *bn7 = divideBigNumbers(bn5, bn6);
    printBigNumber(bn7);

    // remainderBigNumbers
    BigNumber *bn8 = remainderBigNumbers(bn5, bn6);
    printBigNumber(bn8);
        
    return 0;
}
