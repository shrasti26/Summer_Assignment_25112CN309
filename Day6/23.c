#include <stdio.h>

int main() {
    int num, temp;
    int count = 0;
    printf("Enter an integer: ");
    scanf("%d", &num);
    temp = num;
    while (temp > 0) {
        if (temp & 1) {
            count++;
        }

        temp = temp >> 1;
    }

    printf("The number of set bits (1s) in %d is: %d\n", num, count);

    return 0;
}
