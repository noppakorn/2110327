#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  int max_now = v[0];
  int max_so_far = v[0];
  int start = 0;
  int stop = 0;
  int tmp1 = 0;
  int tmp2 = 0;
  for (int i = 1; i < n; ++i) {
    if (v[i] >= max_now + v[i]) {
      max_now = v[i];
      tmp1 = i;
      tmp2 = i;
    } else {
      max_now = max_now + v[i];
      tmp2 = i;
    }
    if (max_now > max_so_far) {
      start = tmp1;
      stop = tmp2;
      max_so_far = max_now;
    }
  }
  int max_now2 = v[0];
  int max_so_far2 = v[0];
  for (int i = 1; i < start; ++i) {
    if (v[i] >= max_now2 + v[i]) {
      max_now2 = v[i];
    } else {
      max_now2 = max_now2 + v[i];
    }
    max_so_far2 = max(max_so_far2, max_now2);
  }

  if (stop + 1 < n) {
    int max_now3 = v[stop + 1];
    int max_so_far3 = v[stop + 1];
    for (int i = stop + 2; i < n; ++i) {
      if (v[i] >= max_now3 + v[i]) {
        max_now3 = v[i];
      } else {
        max_now3 = max_now3 + v[i];
      }
      max_so_far3 = max(max_so_far3, max_now3);
    }
    max_so_far2 = max(max_so_far2, max_so_far3);
  }
  cout << max(max_so_far, max_so_far2 + max_so_far) << "\n";
}