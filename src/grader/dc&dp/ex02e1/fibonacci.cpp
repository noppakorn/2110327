#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
vector<ll> v;
ll fibo(int n) {
    if (v[n] != -1) {
        return v[n];
    }
    ll ret = fibo(n-1) + fibo(n-2);
    v[n] = ret;
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    v = vector<ll>(50, -1);
    v[0] = 0;
    v[1] = 1;
    int n;
    cin >> n;
    cout << fibo(n) << "\n";
}
