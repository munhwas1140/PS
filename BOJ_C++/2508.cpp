#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    string can = "vo^";
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= m - 3; j++) {
            if(a[i].substr(j,3) == ">o<") cnt++;
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j <= n - 3; j++) {
            bool ok = true;
            for(int k = 0; k < 3; k++) {
                if(can[k] != a[j + k][i]) ok = false;
            }
            cnt += ok;
        }
    }
    cout << cnt << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}