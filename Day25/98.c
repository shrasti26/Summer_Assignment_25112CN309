#include <stdio.h>
#include <string.h>

void findCommonCharacters(char str1[], char str2[]) {
    
    int present[256] = {0};
    
    int printed[256] = {0};

    for (int i = 0; str1[i] != '\0'; i++) {
        
        present[(unsigned char)str1[i]] = 1;
    }

    printf("Common characters: ");

    for (int i = 0; str2[i] != '\0'; i++) {
        unsigned char ch = str2[i];
        
    
        if (present[ch] && !printed[ch]) {
            printf("%c ", ch);
            printed[ch] = 1;
        }
    }
    printf("\n");
}

int main() {
    char string1[] = "hello world";
    char string2[] = "woodland";

    printf("String 1: %s\n", string1);
    printf("String 2: %s\n", string2);

    findCommonCharacters(string1, string2);

    return 0;
}
