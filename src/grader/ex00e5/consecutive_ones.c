#include <stdio.h>
int n, k, v[20];
void r(int l) {
    if (l == n) {
        int c = 0;
        for (int j = 0; j < n; ++j) {
            if (v[j]) {
                if (++c >= k) {
                    for (int i = 0; i < n; ++i)
                        printf("%d", v[i]);
                    printf("\n");
                    return;
                }
            } else
                c = 0;
        }
    } else {
        v[l] = 0;
        r(l + 1);
        v[l] = 1;
        r(l + 1);
    }
}
int main() {
    scanf("%d%d", &n, &k);
    r(0);
}