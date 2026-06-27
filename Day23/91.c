#include <stdio.h>
#include <string.h>

int checkAnagram(char str1[], char str2[]) {
    
    int frequency[256] = {0};
    int i;


    if (strlen(str1) != strlen(str2)) {
        return 0; 
    }

    
    for (i = 0; str1[i] != '\0'; i++) {
        frequency[(unsigned char)str1[i]]++;
        frequency[(unsigned char)str2[i]]--;
    }

    
    for (i = 0; i < 256; i++) {
        if (frequency[i] != 0) {
            return 0; 
        }
    }

    return 1; 
}

int main() {
    char s1[100], s2[100];

    printf("Enter first string: ");
    scanf("%s", s1);

    printf("Enter second string: ");
    scanf("%s", s2);

    if (checkAnagram(s1, s2)) {
        printf("The strings are anagrams.\n");
    } else {
        printf("The strings are NOT anagrams.\n");
    }

    return 0;
}
