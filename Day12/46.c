#include <stdio.h>
#include <math.h>
int isArmstrong(int num);
int main() {
    int number;
    printf("Enter an integer: ");
    scanf("%d", &number);
    if (isArmstrong(number)) {
        printf("%d is an Armstrong number.\n", number);
    } else {
        printf("%d is not an Armstrong number.\n", number);
    }
    return 0;
}
int isArmstrong(int num) {
    int originalNum, remainder;
    int digits = 0;
    int result = 0;
    originalNum = num;
    while (originalNum != 0) {
        originalNum /= 10;
        digits++;
    }
    originalNum = num;
    while (originalNum != 0) {
        remainder = originalNum % 10;
        result += (int)pow(remainder, digits);
        
        originalNum /= 10;
    }
    if (result == num) {
        return 1;
    } else {
        return 0;
    }
}
