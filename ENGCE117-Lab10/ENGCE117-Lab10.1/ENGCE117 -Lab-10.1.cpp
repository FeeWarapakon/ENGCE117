#include <stdio.h>

long SumLoop(int n);
long SumRecur(int n);

int main() {
    int n = 10;
    
    printf("SumLoop(n) = %ld\n", SumLoop(n));
    printf("SumRecur(n) = %ld\n", SumRecur(n));

    return 0;
}

long SumLoop(int n) {
    long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

long SumRecur(int n) {
    if (n <= 1) {
        return n;
    } else {
        return n + SumRecur(n - 1);
    }
}