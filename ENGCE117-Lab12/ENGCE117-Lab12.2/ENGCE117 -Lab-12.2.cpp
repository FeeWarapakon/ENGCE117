#include <stdio.h>

int *KnapsackGreedy(int *w, int *v, int n, int wx) {
    int *x = new int[n];
    float *vw = new float[n];
    bool *used = new bool[n];

    for (int i = 0; i < n; i++) {
        x[i] = 0;
        used[i] = false;
        vw[i] = (float)v[i] / w[i];
    }

    int currentWeight = 0;

    for (int count = 0; count < n; count++) {
        int bestIdx = -1;
        float maxVW = -1.0;

        for (int i = 0; i < n; i++) {
            if (!used[i] && vw[i] > maxVW) {
                maxVW = vw[i];
                bestIdx = i;
            }
        }

        if (bestIdx == -1) break;
        used[bestIdx] = true;

        if (currentWeight + w[bestIdx] <= wx) {
            x[bestIdx] = 1;
            currentWeight += w[bestIdx];
        } else {
            x[bestIdx] = 0;
        }
    }

    delete[] vw;
    delete[] used;
    return x;
}

int main() {
    int n = 5, wx = 11;
    int w[5] = { 1, 2, 5, 6, 7 };
    int v[5] = { 1, 6, 18, 22, 28 };

    int *x = KnapsackGreedy(w, v, n, wx);

    for (int i = 0; i < n; i++) printf("%d ", x[i]);

    return 0;
}