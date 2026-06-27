#include <stdio.h>

int main() {
    char str[100];
    int freq[256] = {0}; 
    int i, max_idx = 0;

    printf("Enter a string: ");
    
    scanf("%[^\n]", str); 

    
    for (i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }

    
    for (i = 0; i < 256; i++) {
        if (freq[i] > freq[max_idx]) {
            max_idx = i;
        }
    }

    printf("Maximum occurring character is '%c', appearing %d times.\n", max_idx, freq[max_idx]);

    return 0;
}
