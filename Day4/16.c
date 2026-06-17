#include <stdio.h>
#include <math.h>

int main() {
    int start, end, i, temp, remainder, digits, sum;
    printf("Enter starting number of range: ");
    scanf("%d", &start);
    printf("Enter ending number of range: ");
    scanf("%d", &end);

    printf("Armstrong numbers between %d and %d are:\n", start, end);
    for (i = start; i <= end; i++) {
        temp = i;
        digits = 0;
        sum = 0;
        while (temp != 0) {
            digits++;
            temp /= 10;
        }

        temp = i; 
        while (temp != 0) {
            remainder = temp % 10;
            sum += round(pow(remainder, digits)); 
            temp /= 10;
        }
        if (sum == i) {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}
