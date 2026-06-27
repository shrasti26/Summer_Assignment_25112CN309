#include <stdio.h>
#include <string.h>

void removeDuplicates(char* str) {
    int hash[256] = {0}; 
    int currentIndex = 0; 

    for (int i = 0; str[i] != '\0'; i++) {
        char currentChar = str[i];
        if (hash[(unsigned char)currentChar] == 0) {
            hash[(unsigned char)currentChar] = 1; 
            str[currentIndex] = currentChar;      
            currentIndex++;
        }
    }
    
    
    str[currentIndex] = '\0'; 
}

int main() {
    char str[100];

    printf("Enter a string: ");
    
    scanf("%[^\n]", str); 

    removeDuplicates(str);

    printf("String after removing duplicates: %s\n", str);
    return 0;
}
