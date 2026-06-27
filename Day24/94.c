#include <stdio.h>
#include <string.h>

void compressString(char str[]) {
    int len = strlen(str);
    
    
    for (int i = 0; i < len; i++) {
        int count = 1;
        
        
        while (i < len - 1 && str[i] == str[i + 1]) {
            count++;
            i++; 
        }
        
        
        printf("%c%d", str[i], count);
    }
    printf("\n");
}

int main() {
    char text[] = "AAABBBCCCDDDA";
    
    printf("Original: %s\n", text);
    printf("Compressed: ");
    compressString(text);
    
    return 0;
}
