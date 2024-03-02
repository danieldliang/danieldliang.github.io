// Bovine Genomics Solution: https://usaco.org/index.php?page=viewproblem2&cpid=736
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream cin("cownomics.txt");
    ofstream cout("cownomics.out");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    
    vector<string> spot(n), nospot(n);
    vector<int> r(m);
    for (int i = 0; i < n; ++i) cin >> spot[i];
    for (int i = 0; i < n; ++i) cin >> nospot[i];
    for (int i = 0; i < m; ++i) r[i] = rand() % 10000000;
    int out = m;
    int i = 0, j = 0;
    vector<int> h1(n, 0), h2(n, 0);
    unordered_set<int> h1set = {};
    bool flag;
    while (j < m && i < m) {
        h1set = {};
        for (int k = 0; k < n; ++k) {
            h1[k] += r[j] * spot[k][j];
            h1[k] %= 10000000;
            h1set.insert(h1[k]);
        }
        flag = false;
        for (int k = 0; k < n; ++k) {
            h2[k] += r[j] * nospot[k][j];
            h2[k] %= 10000000;
            if (h1set.find(h2[k]) != h1set.end()) flag = true;
        }

        if (!flag) {
            out = min(out, j - i + 1);
            cout << j << " " << i << endl;
            for (int k = 0; k < n; ++k) {
                h1[k] -= r[i] * spot[k][i];
                h1[k] %= 10000000;
                h2[k] -= r[i] * nospot[k][i];
                h2[k] %= 10000000;
            }
            i++;
        } else {
            j++;
        }
        if (i > j) {
            j = i;
        } 
    }
    cout << out << endl;
}
