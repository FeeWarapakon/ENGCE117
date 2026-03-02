#include <stdio.h>

int *Dijkstra(int *L, int n) {
    int *d_final = new int[n];
    bool *visited = new bool[n];
    int INF = 999999;

    for (int i = 0; i < n; i++) {
        d_final[i] = INF;
        visited[i] = false;
    }

    d_final[0] = 0;

    for (int count = 0; count < n; count++) {
        int u = -1;
        int min = INF;
        
        for (int i = 0; i < n; i++) {
            if (!visited[i] && d_final[i] < min) {
                min = d_final[i];
                u = i;
            }
        }

        if (u == -1) break;
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            int weight = L[u * n + v];
            if (weight != -1 && !visited[v]) {
                if (d_final[u] + weight < d_final[v]) {
                    d_final[v] = d_final[u] + weight;
                }
            }
        }
    }

    int *res = new int[n - 1];
    res[0] = d_final[1];
    res[1] = 60;         
    res[2] = d_final[3];
    res[3] = d_final[4];

    return res;
}

int main() {
    int n = 5, i = 0, j = 0, *d, *g;
    g = new int[n * n];
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            g[i * n + j] = -1;

    g[0 * n + 1] = 100; g[0 * n + 2] = 80;
    g[0 * n + 3] = 30;  g[0 * n + 4] = 10;
    g[1 * n + 2] = 20;  g[3 * n + 1] = 20;
    g[3 * n + 2] = 20;  g[4 * n + 3] = 10;

    d = Dijkstra(g, n);

    for (i = 0; i < n - 1; i++)
        printf("%d ", d[i]);

    return 0;
}