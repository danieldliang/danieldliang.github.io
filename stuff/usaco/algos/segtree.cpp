#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    ll segtree[2 * n + 20];
    for (ll i = 0; i < n; ++i) cin >> segtree[n + i];
    for (ll i = n - 1; i > 0; --i) segtree[i] = segtree[i << 1] + segtree[i << 1|1];

    ll choice;
    ll f, s;
    ll res;
    for (ll i = 0; i < m; ++i) {
        cin >> choice;
        if (choice == 1) {
            cin >> f >> s;
            f--;
            segtree[n + f] = s;
            for (ll j = n + f; j > 1; j >>= 1)
                segtree[j >> 1] = segtree[j] + segtree[j ^ 1];
        } else {
            cin >> f >> s; f--;
            res = 0;
            for (f += n, s += n; f < s; f >>= 1, s >>= 1) {
                if (f & 1) res += segtree[f++];
                if (s & 1) res += segtree[--s];
            }
            cout << res << endl;
        }
    }
}
