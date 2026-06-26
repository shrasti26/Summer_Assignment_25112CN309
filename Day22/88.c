#include <stdio.h>
void removeSpaces(char *str) {
    int i = 0; 
    int j = 0; 

    while (str[i] != '\0') {
        if (str[i] != ' ') {
            str[j] = str[i];
            j++;
        }
        i++;
    }
    str[j] = '\0'; 
}

int main() {
    
    char text[100];

    printf("Enter a string: ");
    
    fgets(text, sizeof(text), stdin);

    removeSpaces(text);

    printf("String after removing spaces: %s\n", text);

    return 0;
}
