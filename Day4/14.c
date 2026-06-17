#include <stdio.h>

int main() {
    int n;
    int first = 0, second = 1, next = 0;
    printf("Enter the position (n) to find its Fibonacci term: ");
    scanf("%d", &n);
    if (n == 0) {
        next = 0;
    } else if (n == 1) {
        next = 1;
    } else {
        for (int i = 2; i <= n; i++) {
            next = first + second; 
            first = second;        
            second = next;         
        }
    }
    printf("The %dth Fibonacci term is: %d\n", n, next);

    return 0;
}
