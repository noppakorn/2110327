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
    int m = (start + stop) / 2;
    int r1 = mss(v, start, m, s);
    int r2 = mss(v, m, stop, s);

    int max_sum_left = get_sum(s, m-1, m-1);
    for (int i = start; i < m-1; ++i) {
        max_sum_left = std::max(max_sum_left, get_sum(s, i, m-1));
    }

    int max_sum_right = get_sum(s, m, m);
    for (int i = m+1; i < stop; ++i) {
        max_sum_right = std::max(max_sum_right, get_sum(s, m, i));
    }
    int r3 = max_sum_left + max_sum_right;

    return std::max(std::max(r1, r2), r3);
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