#include <stdio.h>
#include <stdlib.h> 

void GetSet(int **set_ptr, int *num_members_ptr);

int main() {
    int *data = NULL;
    int num = 0;

    printf("--- Starting Set Data Input Program ---\n");

    GetSet(&data, &num);

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
}

void GetSet(int **set_ptr, int *num_members_ptr) {
    int n;

    // 1. Get the number of members
    printf("Enter the number of members (N) in the set: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Error: Please enter a non-negative integer.\n");
        while (getchar() != '\n'); 
        *num_members_ptr = 0;
        return;
    }
    
    *num_members_ptr = n;

    // Handle zero members case
    if (n == 0) {
        *set_ptr = NULL;
        return;
    }

    // 2. Dynamic Memory Allocation
    *set_ptr = (int *)malloc(n * sizeof(int));

    // Check if allocation was successful
    if (*set_ptr == NULL) {
        printf("Error: Could not allocate memory.\n");
        *num_members_ptr = 0; 
        return;
    }

    // 3. Get each member's value
    printf("Enter the value of %d members:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Member [%d]: ", i + 1);
        
        // Read member value into the allocated array
        if (scanf("%d", &(*set_ptr)[i]) != 1) { 
             printf("Error: Invalid input. Terminating input.\n");
             // Free allocated memory before exiting 
             free(*set_ptr);
             *set_ptr = NULL;
             *num_members_ptr = 0;
             while (getchar() != '\n');
             return;
        }
    }
}