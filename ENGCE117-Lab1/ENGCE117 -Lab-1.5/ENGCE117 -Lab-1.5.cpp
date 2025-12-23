#include <stdio.h>
#include <stdlib.h> 

void GetMatrix(int **value_ptr, int *row, int *col);

int main() {
    int *data = NULL;
    int m = 0;
    int n = 0;

    printf("--- Starting Matrix Data Input Program ---\n");
    GetMatrix(&data, &m, &n);
    if (data != NULL && m > 0 && n > 0) {
        printf("\nReceived Matrix (%d rows x %d columns):\n", m, n);
        
        for (int i = 0; i < m; i++) { 
            for (int j = 0; j < n; j++) { 
                printf("%5d", data[i * n + j]);
            }
            printf("\n");
        }
        free(data);
        data = NULL;
        printf("Memory successfully freed.\n");
    } else {
        printf("\nMatrix input failed or dimensions were zero/invalid.\n");
    }

    printf("--- Program finished ---\n");
    return 0;
}// end main

void GetMatrix(int **value_ptr, int *row, int *col) {
    int m_rows, n_cols;
    long total_size;
    printf("Enter number of rows (m): ");
    if (scanf("%d", &m_rows) != 1 || m_rows <= 0) {
        printf("Error: Invalid row number.\n");
        while (getchar() != '\n');
        *value_ptr = NULL;
        *row = 0;
        *col = 0;
        return;
    }
    printf("Enter number of columns (n): ");
    if (scanf("%d", &n_cols) != 1 || n_cols <= 0) {
        printf("Error: Invalid column number.\n");
        while (getchar() != '\n');
        *value_ptr = NULL;
        *row = 0;
        *col = 0;
        return;
    }
    total_size = (long)m_rows * n_cols;
    *value_ptr = (int *)malloc(total_size * sizeof(int));
    if (*value_ptr == NULL) {
        printf("Error: Could not allocate memory for matrix.\n");
        *row = 0;
        *col = 0;
        return;
    }
    *row = m_rows;
    *col = n_cols;
    printf("Enter %ld matrix elements (%d x %d):\n", total_size, m_rows, n_cols);
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < n_cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            if (scanf("%d", &(*value_ptr)[i * n_cols + j]) != 1) { 
                 printf("Error: Invalid input. Stopping.\n");
                 free(*value_ptr);
                 *value_ptr = NULL;
                 *row = 0;
                 *col = 0;
                 while (getchar() != '\n');
                 return;
            }
        }
    }
}// end GetMatrix