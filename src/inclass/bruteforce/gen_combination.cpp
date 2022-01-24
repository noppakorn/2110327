#include <iostream>
#include <vector>
using namespace std;

void combi(int n, vector<int> &sol, int len) {
    if (len < n) {
        sol[len] = 1;
        combi(n,sol,len+1);
        sol[len] = 0;
        combi(n, sol, len+1);
    } else {
        for (int i = 0; i < n; ++i) {
            if (sol[i] == 1)
                cout << i+1 << " ";
        }
        cout << "." << endl;
    }
}

int main() {
    vector<int> sol(3);
    combi(3,sol,0);
}
