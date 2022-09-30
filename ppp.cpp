#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int a[2001];
int dp[2001][2001];
int go(int s, int e) {
    int &ret = dp[s][e];
    if(ret != -1) return ret;
    if(s == e) return ret = 1;
    if(s + 1 == e) {
        if(a[s] == a[e]) ret = 1;
        else ret = 0;
        return ret ;
    }
    if(a[s] != a[e]) return ret = false;
    return ret = go(s + 1, e - 1);
}
int main() {
    fastio;
    memset(dp,-1,sizeof(dp));
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int m;
    cin >> m;
    while(m--) {
        int t1, t2;
        cin >> t1 >> t2;
        cout << go(t1, t2) << '\n';
    }

    return 0;
}