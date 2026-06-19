#include <stdio.h>
int reverseNumber(int num, int rev);

int main() {
    int number, reversed;
    printf("Enter an integer to reverse: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
    reversed = reverseNumber(number, 0);
    printf("Original number: %d\n", number);
    printf("Reversed number: %d\n", reversed);

    return 0;
}
int reverseNumber(int num, int rev) {
    if (num == 0) {
        return rev;
    }
    int lastDigit = num % 10;
    rev = (rev * 10) + lastDigit;
    return reverseNumber(num / 10, rev);
}
