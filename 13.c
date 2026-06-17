#include <stdio.h>

int main() {
    int terms, i;
    int t1 = 0, t2 = 1, nextTerm;
    printf("Enter the number of terms: ");
    scanf("%d", &terms);

    printf("Fibonacci Series: ");

    for (i = 1; i <= terms; ++i) {
        printf("%d ", t1);

        nextTerm = t1 + t2;

        t1 = t2;
        t2 = nextTerm;
    }

    printf("\n");
    return 0;
}
