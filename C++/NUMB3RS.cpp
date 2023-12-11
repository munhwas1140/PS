#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, d, p;
vector<int> g[50];
double dp[50][101];

double go(int now, int day) {
    if(day == 0) {
        if(now == p) return 1.0;
        return 0.0;
    }
    
    double &ret = dp[now][day];
    if(ret != -1) return ret;

    ret = 0.0;
    for(int next : g[now]) {
        ret += (1.0 / (double)g[next].size()) * go(next, day - 1);
    }
    return ret;
}

void solve() {
    for(int i = 0; i < 50; i++) {
        g[i].clear();
    }

    cin >> n >> d >> p;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int tmp; cin >> tmp;
            if(tmp == 1) {
                g[i].push_back(j);
            }
        }
    }

    for(int i = 0; i < 50; i++) {
        for(int j = 0; j <= 100; j++) {
            dp[i][j] = -1.0;
        }
    }

    int t; cin >> t;
    while(t--) {
        int q;cin >> q;
        cout << go(q, d) << ' ';
    }
    cout << '\n';
}
int main() {
    fastio; 
    int tc; cin >> tc;
    cout << fixed << setprecision(10);
    while(tc--) {
        solve();
    }
    return 0;
}