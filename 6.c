#include <stdio.h>

int main() {
    int num, reverse = 0, remainder;

    // Prompt user for input
    printf("Enter an integer: ");
    scanf("%d", &num);
    while (num != 0) {
        remainder = num % 10;          
        reverse = reverse * 10 + remainder; 
        num /= 10;                     
    }

    printf("Reversed number = %d\n", reverse);

    return 0;
}
