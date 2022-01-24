#include <stdio.h>

void gen(int n, int* sol, int len, int sum, int k) {
    if (len < n) {
        sol[len] = 0;
        gen(n, sol, len + 1, sum, k);
        sol[len] = 1;
        gen(n, sol, len + 1, sum + 1, k);
    } else {
        if (sum == k) {
            for (int i = 0; i < n; ++i) {
                printf("%d", sol[i]);
            }
            printf("\n");
        }
        return;
    }
}

int main() {
    int n, k;
    scanf("%d%d", &k, &n);
    int sol[n];
    gen(n, sol, 0, 0, k);
}