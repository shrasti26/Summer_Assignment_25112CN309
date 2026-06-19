#include <stdio.h>
int main() {
    int num, temp, count = 0;
    printf("Enter any integer: ");
    scanf("%d", &num);
    temp = num;
    if (temp == 0) {
        count = 1;
    } else {
        if (temp < 0) {
            temp = -temp;
        }
        while (temp > 0) {
            temp = temp / 10; 
            count++;         
        }
    }
    printf("The number of digits in %d is: %d\n", num, count);

    return 0;
}
