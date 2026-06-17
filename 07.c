#include <stdio.h>

int main() {
    int num, temp, remainder, product = 1;
    printf("Enter any number: ");
    scanf("%d",&num);
    temp=num;
        while (temp > 0) {
            remainder = temp % 10;      
            product = product * remainder;
            temp = temp / 10; 
        }         

    printf("The product of the digits of %d is: %d\n", num, product);

    return 0; 
}
