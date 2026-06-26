#include <stdio.h>

int main() {
    char lower;

    printf("Enter a lowercase character: ");
    scanf("%c", &lower);


    if (lower >= 'a' && lower <= 'z') {

        char upper = lower - 32; 
        printf("Uppercase equivalent: %c\n", upper);
    } else {
        printf("That is not a lowercase letter.\n");
    }

    return 0;
}
