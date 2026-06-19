#include <stdio.h>

int main() {
    int n, original_n;
    int largest_prime = -1;

    printf("Enter a positive integer: ");
    if (scanf("%d", &n) != 1 || n <= 1) {
        printf("Please enter a valid integer greater than 1.\n");
        return 1;
    }

    original_n = n; 
    while (n % 2 == 0) {
        largest_prime = 2;
        n /= 2;
    }
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            largest_prime = i;
            n /= i;
        }
    }
    if (n > 2) {
        largest_prime = n;
    }

    printf("The largest prime factor of %d is: %d\n", original_n, largest_prime);

    return 0;
}

