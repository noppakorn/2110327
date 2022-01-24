#include <iostream>
#include <vector>
using namespace std;

void recur(vector<bool> &v, int len, int k) {
    if (len == v.size()) {
        int count = 0;
        for (auto x : v) {
            if (x) {
                if (++count >= k) {
                    for (int i = 0; i < v.size(); ++i) {
                        cout << v[i];
                    }
                    cout << "\n";
                    return;
                }
            } else {
                count = 0;
            }
        }
    } else {
        v[len] = 0;
        recur(v, len + 1, k);
        v[len] = 1;
        recur(v, len + 1, k);
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<bool> v(n);
    recur(v, 0, k);
}
