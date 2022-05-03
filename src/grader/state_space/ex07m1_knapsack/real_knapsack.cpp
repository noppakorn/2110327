#include <bits/stdc++.h>
using namespace std;

double w;
int n;
double mx = 0;
vector<pair<double, double>> v;
class State {
  public:
    int idx;
    double sp;
    double sw;
    double upper_bound;
    State(int idx, double sp, double sw, double upper_bound)
        : idx(idx), sp(sp), sw(sw), upper_bound(upper_bound) {}
    bool operator<(const State &other) const {
        return upper_bound < other.upper_bound;
    }
};

double frac_knapsack(int start, double limit) {
    double frac_price = 0;
    double frac_weight = 0;
    for (int i = start; i < n; ++i) {
        if (frac_weight + v[i].second <= limit) {
            frac_weight += v[i].second;
            frac_price += v[i].first;
        } else {
            frac_price += v[i].first / v[i].second * (limit - frac_weight);
            break;
        }
    }
    return frac_price;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> w >> n;
    v = vector<pair<double, double>>(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first;
    }
    for (int i = 0; i < n; ++i) {
        cin >> v[i].second;
    }
    sort(v.begin(), v.end(), [](const auto &left, const auto &right) {
        return left.first / left.second > right.first / right.second;
    });
    priority_queue<State> pq;
    pq.push(State(0, 0, 0, frac_knapsack(0, w)));

    while (!pq.empty()) {
        auto state = pq.top();
        pq.pop();
        if (state.upper_bound < mx)
            break;
        if (state.idx == n) {
            mx = max(mx, state.sp);
        } else {
            pq.push( State(state.idx + 1, state.sp, state.sw, frac_knapsack(state.idx + 1, w - state.sw) + state.sp));
            if (w - state.sw - v[state.idx].second >= 0) {
                pq.push( State(state.idx + 1, state.sp + v[state.idx].first, state.sw + v[state.idx].second, frac_knapsack(state.idx + 1, w - state.sw - v[state.idx].second) + state.sp + v[state.idx].first));
            }
        }
    }
    cout << fixed << setprecision(4) << mx << "\n";
}
