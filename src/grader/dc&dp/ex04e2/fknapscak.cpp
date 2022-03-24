#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    double w;
    int n;
    cin >> w >> n;
    vector<pair<double, double>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first;
    }
    for (int i = 0; i < n; ++i) {
        cin >> v[i].second;
    }
    sort(v.begin(), v.end(),
         [](pair<double, double> a, pair<double, double> b) {
             return a.first / a.second > b.first / b.second;
         });
    double sum_w = 0;
    int pos = 0;
    double price = 0;
    while (sum_w < w && pos < n) {
        if (v[pos].second <= w - sum_w) {
            price += v[pos].first;
            sum_w += v[pos].second;
            pos++;
        } else {
            price += v[pos].first * ((double)(w - sum_w) / v[pos].second);
            break;
        }
    }
    cout << fixed << setprecision(4) << price << "\n";
}