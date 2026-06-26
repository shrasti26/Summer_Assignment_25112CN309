#include <stdio.h>

int main() {
    char str[200];
    int i = 0;
    int count = 0;
    int in_word = 0; 

    printf("Enter a sentence: ");
    
    scanf("%[^\n]s", str); 

    
    while (str[i] != '\0') {
        
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
            in_word = 0;
        } 
        
        else if (in_word == 0) {
            in_word = 1; 
            count++;     
        }
        i++; 
    }

    printf("Total number of words: %d\n", count);

    return 0;
}
