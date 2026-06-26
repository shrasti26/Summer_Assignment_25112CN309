#include <stdio.h>
int calculateSum(int a, int b);

int main() {
    int num1, num2, sum;
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    sum = calculateSum(num1, num2);
    printf("The sum of %d and %d is: %d\n", num1, num2, sum);

    return 0;
}
int calculateSum(int a, int b) {
    return a + b; // Returns the sum of a and b
}
