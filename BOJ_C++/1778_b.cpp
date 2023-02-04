#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> p(n + 1), a(m), pos(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }

    for(int i = 0; i < m; i++) {
        cin >> a[i];
    }


    int ans = 1e9;
    for(int i = 0; i < m - 1; i++) {
        if(pos[a[i + 1]] <= pos[a[i]] || pos[a[i + 1]] > pos[a[i]] + d) {
            ans = 0;
            break;
        }

        ans = min(ans, pos[a[i + 1]] - pos[a[i]]);

        int t1 = n - pos[a[i + 1]];
        int t2 = pos[a[i]] - 1;
        int dist = pos[a[i + 1]] - pos[a[i]];

        if(dist > d) continue;
        else {
            dist = d - dist;
            if(dist < t1 + t2) {
                ans = min(ans, dist + 1);
            }
        }
    }

    cout << ans << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}