#include <stdio.h>

void gen(int* n, int* k, char* sol, int len, int sum) {
    if (len < *n) {
        sol[len] = '0';
        gen(n,k,sol, len + 1, sum);
        sol[len] = '1';
        gen(n,k,sol, len + 1, sum + 1);
    } else if (sum == *k) {
        sol[*n] = '\0';
        printf("%s\n", sol);
    }
}

int main() {
    int n,k;
    scanf("%d%d", &k, &n);
    char sol[n+1];
    gen(&n, &k,sol, 0, 0);
}