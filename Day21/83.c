#include <stdio.h>

int main() {
    char str[100];
    int vowels = 0;
    int consonants = 0;

    printf("Enter a word or phrase: ");
    
    
    scanf("%[^\n]", str);

    int i = 0;
    while (str[i] != '\0') {
        char ch = str[i];

        
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            vowels++;
        }
        
        else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            consonants++;
        }

        i++; 
    }

    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);

    return 0;
}
