#include <stdio.h>
#include <string.h>

void reverse( char str1[], char str2[] ) {
    int len = strlen(str1);
    int i, j;

    for (i = 0, j = len - 1; i < len; i++, j--) {
        str2[i] = str1[j];
    }
    
    str2[len] = '\0';
}

int main() {
    char text1[50] = "I Love You";
    char out1[50];
    reverse(text1, out1);
    printf("Test Case 1:\n");
    printf("Input:  \"%s\"\n", text1);
    printf("Output: \"%s\"\n", out1);
    printf("--- \n");

    char text2[50] = "Hello World";
    char out2[50];
    reverse(text2, out2);
    printf("Test Case 2:\n");
    printf("Input:  \"%s\"\n", text2);
    printf("Output: \"%s\"\n", out2);
    printf("--- \n");

    char str1[50] = "I love you";
    char str2[50];
    reverse(str1, str2);
    printf("Example Test:\n");
    printf("Input:  \"%s\"\n", str1);
    printf("Output: \"%s\"\n", str2);
    printf("--- \n");

    return 0;
}//end function