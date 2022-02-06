#include <bits/stdc++.h>
#include <functional>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (auto &x : v) {
        cin >> x.first >> x.second;
    }
    std::sort(v.begin(), v.end(), std::greater<pair<int,int>>());
    int c = 0;
    int max = 0;
    for (auto &x : v) {
        if (x.second > max) {
            max = x.second;
            ++c;
        }
    }
    cout << c << "\n";
}