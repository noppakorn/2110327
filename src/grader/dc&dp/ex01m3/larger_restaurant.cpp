#include <bits/stdc++.h>
using namespace std;

long long time_to_queue(long long time, vector<int> &chef) {
    long long ret = 0;
    for (auto &x : chef)
        ret += time / x;
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> chef(n);
    for (int i = 0; i < n; ++i)
        cin >> chef[i];
    std::sort(chef.begin(), chef.end());
    for (int i = 0; i < k; ++i) {
        long long curr_cust;
        cin >> curr_cust;
        if (curr_cust < n)
            cout << "0\n";
        else {
            curr_cust -= n;
            long long left = 0;
            long long right = chef[0] * curr_cust;
            while (left < right) {
                long long mid = (left + right) >> 1;
                if (curr_cust <= time_to_queue(mid, chef))
                    right = mid;
                else
                    left = mid + 1;
            }
            cout << right << "\n";
        }
    }
}