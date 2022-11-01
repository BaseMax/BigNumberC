#include "BigNumber.h"

/**
 * @brief Create a Big Number object
 * 
 * @param size 
 * @return BigNumber* 
 */
BigNumber* createBigNumber(int size) {
    BigNumber *bn = malloc(sizeof(BigNumber));
    bn->digits = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        bn->digits[i] = 0;
    }
    bn->size = size;
    return bn;
}

/**
 * @brief Set the Big Number object
 * 
 * @param bn
 * @param digits
 * @param size
 */
void setBigNumber(BigNumber *bn, int *digits, int size) {
    for (int i = 0; i < size; i++) {
        bn->digits[i] = digits[size - i - 1];
    }
    bn->size = size;
}

/**
 * @brief Create a Big Number object and set it digits
 * 
 * @param digits
 * @param size
 * @return BigNumber* 
 */
BigNumber* createAndSetBigNumber(int *digits, int size) {
    BigNumber *bn = createBigNumber(size);
    setBigNumber(bn, digits, size);
    return bn;
}


/**
 * @brief Destroy the Big Number object
 * 
 * @param bn 
 */
void destroyBigNumber(BigNumber *bn) {
    free(bn->digits);
    free(bn);
}

/**
 * @brief Print the Big Number object
 * 
 * @param bn 
 */
void printBigNumber(BigNumber *bn) {
    if (bn == NULL) printf("NULL");
    else {
        int isZero = 1;
        for (int i = 0; i < bn->size; i++) {
            if (bn->digits[i] != 0) {
                isZero = 0;
                break;
            }
        }
        if (isZero) printf("0");
        else for (int i = bn->size - 1; i >= 0; i--) printf("%d", bn->digits[i]);
    }

    printf("\n");
}

/**
 * @brief Add two Big Numbers
 * 
 * @param bn1 
 * @param bn2 
 * @return BigNumber* 
 */
BigNumber* addBigNumbers(BigNumber *bn1, BigNumber *bn2) {
    BigNumber *result = createBigNumber(bn1->size + 1);
    int carry = 0;
    for (int i = 0; i < bn1->size; i++) {
        int sum = bn1->digits[i] + bn2->digits[i] + carry;
        result->digits[i] = sum % 10;
        carry = sum / 10;
    }
    result->digits[bn1->size] = carry;
    return result;
}

/**
 * @brief Multiply two Big Numbers
 * 
 * @param bn1 
 * @param bn2 
 * @return BigNumber* 
 */
BigNumber* multiplyBigNumbers(BigNumber *bn1, BigNumber *bn2) {
    BigNumber *result = createBigNumber(bn1->size + bn2->size);
    for (int i = 0; i < bn1->size; i++) {
        for (int j = 0; j < bn2->size; j++) {
            result->digits[i + j] += bn1->digits[i] * bn2->digits[j];
        }
    }
    for (int i = 0; i < result->size; i++) {
        result->digits[i + 1] += result->digits[i] / 10;
        result->digits[i] %= 10;
    }
    return result;
}

/**
 * @brief Deep copy a Big Number
 * 
 * @param bn
 * @return BigNumber* 
 */
BigNumber* copyBigNumber(BigNumber *bn) {
    BigNumber *result = createBigNumber(bn->size);
    for (int i = 0; i < bn->size; i++) {
        result->digits[i] = bn->digits[i];
    }
    return result;
}

/**
 * @brief Minus two Big Numbers
 * 
 * @param bn1
 * @param bn2
 * @return BigNumber*
 */
BigNumber* minusBigNumbers(BigNumber *bn1, BigNumber *bn2) {
    BigNumber *result = createBigNumber(bn1->size);
    int carry = 0;
    for (int i = 0; i < bn1->size; i++) {
        int sum = bn1->digits[i] - bn2->digits[i] - carry;
        if (sum < 0) {
            sum += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        result->digits[i] = sum;
    }
    return result;
}

/**
 * @brief Divide two Big Numbers
 * 
 * @param bn1
 * @param bn2
 * @return BigNumber*
 */
BigNumber* divideBigNumbers(BigNumber *bn1, BigNumber *bn2) {
    BigNumber *result = createBigNumber(bn1->size);
    BigNumber *temp = createBigNumber(bn1->size);
    for (int i = bn1->size - 1; i >= 0; i--) {
        for (int j = bn1->size - 1; j > i; j--) {
            temp->digits[j] = temp->digits[j - 1];
        }
        temp->digits[i] = bn1->digits[i];
        int count = 0;
        while (1) {
            BigNumber *temp2 = multiplyBigNumbers(bn2, createBigNumber(1));
            if (temp2->digits[0] > temp->digits[0]) {
                break;
            }
            destroyBigNumber(temp2);
            count++;
        }
        result->digits[i] = count;
        BigNumber *temp3 = multiplyBigNumbers(bn2, createBigNumber(count));
        BigNumber *temp4 = minusBigNumbers(temp, temp3);
        destroyBigNumber(temp3);
        for (int j = 0; j < bn1->size; j++) {
            temp->digits[j] = temp4->digits[j];
        }
        destroyBigNumber(temp4);
    }
    destroyBigNumber(temp);
    return result;
}

/**
 * @brief Remainder two Big Numbers
 * 
 * @param bn1
 * @param bn2
 * @return BigNumber*
 */
BigNumber* remainderBigNumbers(BigNumber *bn1, BigNumber *bn2) {
    BigNumber *result = createBigNumber(bn1->size);
    BigNumber *temp = createBigNumber(bn1->size);
    for (int i = bn1->size - 1; i >= 0; i--) {
        for (int j = bn1->size - 1; j > i; j--) {
            temp->digits[j] = temp->digits[j - 1];
        }
        temp->digits[i] = bn1->digits[i];
        int count = 0;
        while (1) {
            BigNumber *temp2 = multiplyBigNumbers(bn2, createBigNumber(1));
            if (temp2->digits[0] > temp->digits[0]) {
                break;
            }
            destroyBigNumber(temp2);
            count++;
        }
        BigNumber *temp3 = multiplyBigNumbers(bn2, createBigNumber(count));
        BigNumber *temp4 = minusBigNumbers(temp, temp3);
        destroyBigNumber(temp3);
        for (int j = 0; j < bn1->size; j++) {
            temp->digits[j] = temp4->digits[j];
        }
        destroyBigNumber(temp4);
    }
    for (int i = 0; i < bn1->size; i++) {
        result->digits[i] = temp->digits[i];
    }
    destroyBigNumber(temp);
    return result;
}

/**
 * @brief Compare two Big Numbers
 * 
 * @param bn1
 * @param bn2
 * @return int
 */
int compareBigNumbers(BigNumber *bn1, BigNumber *bn2) {
    for (int i = bn1->size - 1; i >= 0; i--) {
        if (bn1->digits[i] > bn2->digits[i]) {
            return 1;
        } else if (bn1->digits[i] < bn2->digits[i]) {
            return -1;
        }
    }
    return 0;
}
