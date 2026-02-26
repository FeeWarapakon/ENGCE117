#include <stdio.h>
#include <stdlib.h> 


int *GetSet(int *num_members_ptr);
// ************************* Main Function ************************
// ************************************************************

int main() {
    int *data = NULL;
    int num = 0;
    printf("--- Starting Set Data Input Program ---\n");
    data = GetSet(&num);
    if (data != NULL && num > 0) {
        printf("\n Received Set Data (%d members):\n", num);
        printf("{ ");
        for (int i = 0; i < num; i++) {
            printf("%d", data[i]);
            if (i < num - 1) {
                printf(", ");
            }
        }
        printf(" }\n");
        free(data);
        data = NULL;
        printf("🧹 Memory successfully freed.\n");

    } else if (num == 0) {
        printf("\n No members in the set (N = 0).\n");
    } else {
        printf("\n Error occurred during input or memory allocation.\n");
    }

    printf("--- Program finished ---\n");
    return 0;
}// end main

int *GetSet(int *num_members_ptr) {
    int n;
    printf("Enter the number of members (N) in the set: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Error: Please enter a non-negative integer.\n");
        while (getchar() != '\n'); 
        *num_members_ptr = 0;
        return NULL;
    }
    *num_members_ptr = n;
    if (n == 0) {
        return NULL;
    }
    int *set_ptr = (int *)malloc(n * sizeof(int));
    if (set_ptr == NULL) {
        printf("Error: Could not allocate memory.\n");
        *num_members_ptr = 0;
        return NULL;
    }
    printf("Enter the value of %d members:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Member [%d]: ", i + 1);
        
        if (scanf("%d", &set_ptr[i]) != 1) { 
             printf("Error: Invalid input. Terminating input.\n");
             free(set_ptr);
             *num_members_ptr = 0;
             while (getchar() != '\n');
             return NULL;
        }
    }
    return set_ptr;
}// end GetSet