#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, w;
int V[101], W[101];
int dp[1001][101];
int go(int wei, int idx) {
    if(wei < 0) return -1e9;
    if(idx == n) return 0;

    int &ret = dp[wei][idx];
    if(ret != -1) return ret;
    ret = max(go(wei, idx + 1), go(wei - W[idx], idx + 1) + V[idx]);
    return ret;
}
void trace(int wei, int idx, vector<int> &a) {
    if(idx == n) return;
    if(go(wei, idx + 1) == go(wei, idx)) {
        trace(wei, idx + 1, a);
    } else {
        a.push_back(idx);
        trace(wei - W[idx], idx + 1, a);
    }
    return ;
}
void solve() {
    cin >> n >> w;
    vector<string> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> W[i] >> V[i];
    }

    memset(dp,-1,sizeof(dp));
    go(w, 0);
    vector<int> seq;
    trace(w, 0, seq);
    cout << go(w, 0) << ' ' << seq.size() << '\n';
    for(int x : seq) {
        cout << a[x] << '\n';
    }
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}