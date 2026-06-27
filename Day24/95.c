#include <stdio.h>
#include <string.h>

int main() {
    char str[200];
    char longest[50] = "";
    char current[50] = "";
    int i = 0, cur_idx = 0;

    printf("Enter a sentence: ");
    
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    while (1) {
        
        if (str[i] == ' ' || str[i] == '\0') {
            current[cur_idx] = '\0'; 
            if (strlen(current) > strlen(longest)) {
                strcpy(longest, current);
            }

            cur_idx = 0; 

            if (str[i] == '\0') {
                break; 
            }
        } else {
            
            current[cur_idx++] = str[i];
        }
        i++;
    }

    printf("The longest word is: '%s'\n", longest);
    printf("Length: %lu\n", strlen(longest));

    return 0;
}
