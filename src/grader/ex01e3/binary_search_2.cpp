#include <iostream>
#include <vector>
using namespace std;

int search(int k, vector<int> &v, int l, int r) {
    if (l == r) {
        if (v[l] == k) {
            return v[l];
        } else {
            while (l >= 0) {
                if (v[l] < k)
                    return v[l];
                l--;
            }
            return -1;
        }
    }

    int mid = (l + r) / 2;
    if (v[mid] >= k) {
        return search(k, v, l, mid);
    } else {
        return search(k, v, mid + 1, r);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (int i = 0; i < m; ++i) {
        int tmp;
        cin >> tmp;
        cout << search(tmp, v, 0, v.size() - 1) << "\n";
    }
}