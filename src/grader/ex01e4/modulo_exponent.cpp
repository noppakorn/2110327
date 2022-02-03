#include <stdio.h>

int mod_expo(int x, int n, int k) {
    if (n == 1) return x % k;
    int res = mod_expo(x, n / 2, k);
    if (n % 2 == 0) return (res * res) % k;
    return ((res * res) % k) * x % k;
}

int main() {
    int x, n ,k;
    scanf("%d%d%d", &x, &n, &k);
    printf("%d\n", mod_expo(x, n, k));
}