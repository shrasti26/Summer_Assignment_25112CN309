#include <stdio.h>

int main() {
    int n1, n2, temp;

    printf("Enter two integers: ");
    scanf("%d %d", &n1, &n2);
    while (n2 != 0) {
        temp = n2;
        n2 = n1 % n2;
        n1 = temp;
    }

    printf("GCD = %d\n", n1);

    return 0;
}
