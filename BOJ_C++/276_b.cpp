#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
vector<int> g[100001];
int main() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }

    for(int i = 1; i <= n; i++) {
        cout << g[i].size() << ' ';
        sort(g[i].begin(), g[i].end());
        for(int x : g[i]) {
            cout << x << ' ';
        }
        cout << '\n';
    }

    return 0;
}