#include <bits/stdc++.h>
#include <vector>
using namespace std;

set<pair<int, int>> gale_shapley(int n, vector<vector<int>> pm,
                                 vector<vector<int>> pw) {
    set<pair<int, int>> ret;
    map<int, int> free_man;
    map<int, int> proposed_man;
    set<int> free_woman;
    map<int, int> proposed_woman;
    for (int i = 0; i < n; ++i) {
        free_man[i] = 0;
        free_woman.insert(i);
    }

    while (free_man.size()) {
        int m_pref = pm[free_man.begin()->first][free_man.begin()->second];
        free_man.begin()->second++;
        auto it = free_woman.find(m_pref);
        if (it != free_woman.end()) {
            proposed_woman.insert({*it, m_pref});
            free_woman.erase(it);
            proposed_man.insert(*free_man.begin());
            free_man.erase(free_man.begin());
        } else {
            auto it2 = proposed_woman.find(m_pref);
            for (auto x : pw[it2->first]) {
                if (x == it2->first) {
                    break;
                }
                else if (x == free_man.begin()->first) {
                    free_man.insert(*it2);
                    proposed_man.erase(it2);
                    proposed_woman[it2->first] = free_man.begin()->first;
                    proposed_man.insert(*it2);
                    break;
                }
            }
        }
    }
    for (auto x : proposed_man) {
        ret.insert(x);
    }
    return ret;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> pm, pw;
    for (int i = 0; i < n; ++i) {
        vector<int> x(n);
        for (int j = 0; j < n ; ++j) {
            cin >> x[j];
        }
        pm.emplace_back(x);
    }
    for (int i = 0; i < n; ++i) {
        vector<int> x(n);
        for (int j = 0; j < n ; ++j) {
            cin >> x[j];
        }
        pw.emplace_back(x);
    }
    set<pair<int, int>> s = gale_shapley(n, pm, pw);
    for (auto e : s) {
        cout << e.first << ": " << e.second << "\n";
    }
}
