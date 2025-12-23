#include <stdio.h>
#include <stdlib.h> 

int GetSet(int **set_ptr);

int main() {
    int *data = NULL; 
    int num = 0;      

    printf("--- Set Data Input ---\n");
    num = GetSet(&data);

    if (num > 0 && data != NULL) {
        printf("\nSet Size (num): %d\n", num);
        printf("Set Data: {");
        for (int i = 0; i < num; i++) {
            printf("%d%s", data[i], (i < num - 1 ? ", " : ""));
        }
        printf("}\n");
        free(data);
        data = NULL;
    } else if (num == 0) {
        printf("\nSet is empty (num = 0).\n");
    } else {
        printf("\nError: Data input or memory allocation failed.\n");
    }

    return 0;
}// end main

int GetSet(int **set_ptr) {
    int n;

    printf("Enter the number of members (N): ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Error: Invalid number input.\n");
        while (getchar() != '\n'); 
        return 0;
    }
    
    if (n == 0) {
        *set_ptr = NULL;
        return 0;
    }
    *set_ptr = (int *)malloc(n * sizeof(int));
    if (*set_ptr == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 0;
    }
    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Member [%d]: ", i + 1);
        if (scanf("%d", &(*set_ptr)[i]) != 1) { 
             printf("Error: Invalid value input. Stopping.\n");
             free(*set_ptr);
             *set_ptr = NULL;
             while (getchar() != '\n');
             return 0;
        }
    }
    return n;
}// end GetSet