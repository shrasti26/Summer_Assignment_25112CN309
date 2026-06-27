#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int areRotations(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1 != len2) {
        return 0;
    }
    char *temp = (char *)malloc(sizeof(char) * (len1 * 2 + 1));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return 0;
    }

    strcpy(temp, str1);
    strcat(temp, str1);
    if (strstr(temp, str2) != NULL) {
        free(temp); 
        return 1;   
    }

    free(temp);
    return 0;     
}

int main() {
    char str1[] = "ABCD";
    char str2[] = "CDAB";

    if (areRotations(str1, str2)) {
        printf("Yes, '%s' is a rotation of '%s'\n", str2, str1);
    } else {
        printf("No, '%s' is not a rotation of '%s'\n", str2, str1);
    }

    return 0;
}
