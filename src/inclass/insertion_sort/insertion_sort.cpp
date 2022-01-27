#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void insertion_dc(vector<int> &v, int l, int r) {
    if (l != r) {
        insertion_dc(v, l, r - 1);
        int curr = r - 1;
        int tmp = v[r];
        while (v[curr] > tmp) {
            v[curr + 1] = v[curr];
            curr--;
        }
        v[curr + 1] = tmp;
    }
}

void insertion(vector<int> &a) { insertion_dc(a, 0, a.size() - 1); }

int main() {
    int n = 30;
    vector<int> v(n);
    for (int i = 0; i < 30; ++i) {
        v[i] = i + 1;
    }
    random_shuffle(v.begin(), v.end());
    for (int i = 0; i < 7; ++i) {
        v.pop_back();
    }
    for (auto x : v) {
        cout << x << " ";
    }
    cout << "\n";
    insertion(v);
    for (auto x : v) {
        cout << x << " ";
    }
    cout << "\n";
}