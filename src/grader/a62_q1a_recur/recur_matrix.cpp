#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
void gen(vector<vector<int>> &v, int a, int b, int top, int bottom, int left,
         int right) {
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    vector<vector<int>> v;
    int len = 1 << a;
    gen(v, a, b, 0, 0, len, len);
}
