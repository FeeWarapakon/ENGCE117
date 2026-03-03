#include <stdio.h>

int max_v = 0;
int *best_x = NULL;

int KnapsackBT(int *w, int *v, int n, int wx, int i, int *x) {
    if (best_x == NULL) {
        best_x = new int[n];
        for (int k = 0; k < n; k++) best_x[k] = 0;
    }
    if (i == n) {
        int current_v = 0;
        int current_w = 0;
        for (int k = 0; k < n; k++) {
            if (x[k] == 1) {
                current_w += w[k];
                current_v += v[k];
            }
        }
        if (current_w <= wx && current_v > max_v) {
            max_v = current_v;
            for (int k = 0; k < n; k++) best_x[k] = x[k];
        }
        return max_v;
    }

    x[i] = 0;
    KnapsackBT(w, v, n, wx, i + 1, x);
    x[i] = 1;
    KnapsackBT(w, v, n, wx, i + 1, x);
    if (i == 0) {
        for (int k = 0; k < n; k++) x[k] = best_x[k];
    }
    return max_v;
}

int main() {
    int n = 5, wx = 11;
    int w[5] = { 1, 2, 5, 6, 7 };
    int v[5] = { 1, 6, 18, 22, 28 };
    int *x, vx;
    
    x = new int[n];
    vx = KnapsackBT(w, v, n, wx, 0, x);
    printf("Value = %d\n", vx);
    for (int i = 0; i < n; i++) printf("%d ", x[i]);

    return 0;
}