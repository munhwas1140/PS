#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n, q;
    cin >> n >> q;
    vector<vector<int>> a(n);
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        for(int j = 0; j < tmp; j++) {
            int t; cin >> t;
            a[i].push_back(t);
        }
    }

    while(q--) {
        int s, t;
        cin >> s >> t;
        cout << a[s - 1][t - 1] << '\n';
    }

    return 0;
}