#include <stdio.h>
int n, k;
char s[20];

void recur(int len, int c, int done, char s[20]) {
    if (c == k)
        done = 1;
    if (len == n) {
        if (done)
            printf("%s\n", s);
    } else {
        s[len] = '0';
        recur(len + 1, 0, done, s);
        s[len] = '1';
        recur(len + 1, c + 1, done, s);
    }
}

int main() {
    scanf("%d%d", &n, &k);
    recur(0, 0, 0, s);
}
