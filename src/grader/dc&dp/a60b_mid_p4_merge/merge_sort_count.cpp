#include <algorithm>
#include <bits/stdc++.h>
#include <random>
using namespace std;
int sum = 0;

void merge(vector<int> &v, int start, int mid, int stop, vector<int> &tmp) {
    int a = start;
    int b = mid;
    for (int i = start; i < stop; ++i) {
        if (a >= mid)
            tmp[i] = v[b++];
        else if (b >= stop)
            tmp[i] = v[a++];
        else
            tmp[i] = v[a] < v[b] ? v[a++] : v[b++];
    }
    for (int i = start; i < stop; ++i) {
        v[i] = tmp[i];
    }
}

void mergesort(vector<int> &a, int start, int stop, vector<int> &tmp) {
    sum++;
    cout << start << " " << stop << "\n";
    bool b = false;
    for (int i = start; i < stop - 1; ++i) {
        if (a[i] > a[i + 1]) {
            b = true;
            break;
        }
    }

    if (b && start < stop) {
        int mid = (start + stop) >> 1;
        mergesort(a, start, mid, tmp);
        mergesort(a, mid, stop, tmp);
        merge(a, start, mid, stop, tmp);
    } else {
        return;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i  =0 ; i < n; ++i) {
        cin >> v[i];
    }
    vector<int> tmp(n);
    mergesort(v, 0, n, tmp);
    cout << sum << endl;
}