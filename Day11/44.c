#include <stdio.h>
int findFactorial(int n);
int main() {
    int number;
    int result;
    printf("Enter a positive integer: ");
    scanf("%d", &number);
    if (number < 0) {
        printf("Error: Factorial of a negative number doesn't exist.\n");
    } else {
        result = findFactorial(number);
        printf("Factorial of %d is %d\n", number, result);
    }
    return 0;
}
int findFactorial(int n) {
    int fact = 1;
    
    for (int i = 1; i <= n; i++) {
        fact *= i; 
    }
    
    return fact;
}
