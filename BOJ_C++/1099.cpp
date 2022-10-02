#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
vector<vector<int>> cnt(50, vector<int>(26,0));
vector<string> a;
string str;
int dp[51];

int go(int idx) {
    int &ret = dp[idx];
    if(ret != -1) return ret;
    if(idx == str.size()) return ret = 0;
    
    ret = 1e9;
    for(int i = 0; i < n; i++) {
        if(idx + a[i].size() > str.size()) continue;
        vector<int> tmp = cnt[i];
        bool ok = true;
        int tt = 0;
        for(int j = 0; j < a[i].size(); j++) {
            tmp[str[idx + j] - 'a']--;
            if(tmp[str[idx + j] - 'a'] < 0) {
                ok = false;
                break;
            }
            if(a[i][j] != str[idx + j]) {
                tt++;
            }
        }
        if(ok) {
            ret = min(ret, go(idx + a[i].size()) + tt);
        }
    }
    return ret;
}
int main() {
    fastio;
    cin >> str >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j = 0; j < a[i].size(); j++) {
            cnt[i][a[i][j] - 'a']++;
        }
    }
    memset(dp,-1,sizeof(dp));

    cout << (go(0) == 1e9 ? -1 : dp[0]) << '\n'; 
    return 0;
}
