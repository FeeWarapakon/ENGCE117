#include <stdio.h>
#include <string.h>

void explode( char str1[], char splitter, char str2[][10], int *count );

void explode( char str1[], char splitter, char str2[][10], int *count ) {
    int i = 0;
    int k = 0;
    int j = 0;

    *count = 0;

    while (str1[i] != '\0') {
        
        if (str1[i] != splitter) {
            
            if (j < 9) { 
                str2[k][j] = str1[i];
                j++;
            }
        } else {
            str2[k][j] = '\0';
            k++;
            j = 0;
        }
        
        i++;
    }

    str2[k][j] = '\0'; 

    *count = k + 1;
}

int main() {
    char out[ 20 ][ 10 ] ;
    int num ;
    int i;
    
    char str1_test1[50] = "I/Love/You";
    char splitter_test1 = '/';
    
    explode( str1_test1, splitter_test1, out, &num ) ;
    
    printf("Test Case 1 (I/Love/You):\n");
    printf("Input: str1=\"%s\", splitter='%c'\n", str1_test1, splitter_test1);
    printf("count = %d\n", num);
    
    for (i = 0; i < num; i++) {
        printf("str2[%d] = \"%s\"\n", i, out[i]);
    }
    printf("--- \n");
    
    char str1_test2[50] = "Hello World:Welcome:To:C";
    char splitter_test2 = ':';
    
    explode( str1_test2, splitter_test2, out, &num ) ;
    
    printf("Test Case 2 (Hello World:Welcome:To:C):\n");
    printf("Input: str1=\"%s\", splitter='%c'\n", str1_test2, splitter_test2);
    printf("count = %d\n", num);
    
    for (i = 0; i < num; i++) {
        printf("str2[%d] = \"%s\"\n", i, out[i]);
    }
    printf("--- \n");
    
    return 0 ;
}//end function