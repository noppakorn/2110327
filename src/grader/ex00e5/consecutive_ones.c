#include <stdio.h>
int n, k, v[20];
void r(int l, int c, int f) {
    if (l == n) {
        if (f) {
            for (int i = 0; i < n; ++i)
                printf("%d", v[i]);
            printf("\n");
        }
        return;
    }
    v[l] = 0;
    r(l + 1, 0, f);
    v[l] = 1;
    r(l + 1, c + 1, c + 1 >= k || f);
}
int main() {
    scanf("%d%d", &n, &k);
    r(0, 0, 0);
}
