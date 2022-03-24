#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    if (n == 1)
        return v[0];
    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum += v[i];
    int curr_max = v[0], max_so_far = v[0], curr_min = v[0], min_so_far = v[0];
    for (int i = 1; i < n; ++i) {
        curr_max = max(curr_max + v[i], v[i]);
        max_so_far = max(max_so_far, curr_max);
        curr_min = min(curr_min + v[i], v[i]);
        min_so_far = min(min_so_far, curr_min);
    }
    if (min_so_far == sum)
        cout << max_so_far << "\n";
    else
        cout << max(max_so_far, sum - min_so_far) << "\n";
}