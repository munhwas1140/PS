#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n; 
int dp[1000001][2];
vector<int> g[1000001];
int go(int now, int pre, int s) {
    int &ret = dp[now][s];
    if(ret != -1) return ret;
    if(s == 1) {
        ret = 1;
        for(int &next : g[now]) {
            if(next != pre) {
                ret += min(go(next, now, 0), go(next, now, 1));
            }
        }
    } else {
        ret = 0;
        for(int &next : g[now]) {
            if(next != pre) {
                ret += go(next, now, 1);
            }
        }
    }
    return ret;
}
int main() {
    fastio;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }

    memset(dp,-1,sizeof(dp));
    cout << min(go(1, -1, 0), go(1, -1, 1)) << '\n';

    return 0;
}