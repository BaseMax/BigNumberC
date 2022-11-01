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
    
    
    return 0;
}
