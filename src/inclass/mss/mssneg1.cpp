#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
int get_sum(vector<int> &s, int a, int b) {
    if (a == 0) return s[b];
    return s[b] - s[a-1];
}

int mss(vector<int> &v, int start, int stop, vector<int> &s) {
    if (start == stop - 1) {
        return v[start];
    }
    int r = mss(v, start, stop-1, s);

    int max_sum_curr = get_sum(s, stop-1, stop-1);
    for (int i = stop-2; i >= 0; --i) {
        max_sum_curr = std::max(max_sum_curr, get_sum(s, i, stop-1));
    }

    return std::max(r, max_sum_curr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<int> s(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += v[i];
        s[i] = sum;
    }
    cout << mss(v, 0, v.size(), s) << "\n";
}