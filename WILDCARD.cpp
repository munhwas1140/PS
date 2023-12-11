#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
string W, S;
int dp[101][101];
bool go(int w, int s) {
    int &ret = dp[w][s];
    if(ret != -1) return ret;

    if(s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])) {
        return ret = go(w + 1, s + 1);
    }


    if(w == W.size()) {
        return ret = (s == S.size());
    }
    
    if(W[w] == '*') {
        if(go(w + 1, s) || (s < S.size() && go(w, s + 1))) {
            return ret = 1;
        }
    }
    return ret = 0;
}
void solve() {
    cin >> W;
    int n; cin >> n;
    vector<string> ans;
    while(n--) {
        cin >> S;
        memset(dp,-1,sizeof(dp));
        if(go(0, 0)) {
            ans.push_back(S);
        }
    }
    sort(ans.begin(), ans.end());
    for(string x : ans) cout << x << '\n';
    return ;
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}