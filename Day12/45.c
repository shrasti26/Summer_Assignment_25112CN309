#include <stdio.h>
int isPalindrome(int num) {
    if (num < 0) {
        return 0;
    }

    int reversed = 0;
    int remainder;
    int original = num;
    while (num != 0) {
        remainder = num % 10;        
        reversed = (reversed * 10) + remainder; 
        num /= 10;                     
    }
    if (original == reversed) {
        return 1; 
    } else {
        return 0;
    }
}

int main() {
    int number;

    printf("Enter an integer: ");
    scanf("%d", &number);
    if (isPalindrome(number)) {
        printf("%d is a palindrome.\n", number);
    } else {
        printf("%d is not a palindrome.\n", number);
    }

    return 0;
}

