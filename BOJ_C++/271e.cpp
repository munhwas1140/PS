#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m, k;
int main() {
    fastio;
    cin >> n >> m >> k;
    vector<int> a(m), b(m), c(m);
    vector<ll> dist(n, 9e18);
    dist[0] = 0;

    for(int i = 0; i < m; i++) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--;
        b[i]--;
    }


    while(k--) {
        int e; cin >> e;
        e--;
        if(dist[b[e]] > dist[a[e]] + c[e]) {
            dist[b[e]] = dist[a[e]] + c[e];
        }
    }

    if(dist[n - 1] == 9e18) {
        cout << -1 << '\n';
    } else {
        cout << dist[n - 1] << '\n';
    }
    return 0;
}