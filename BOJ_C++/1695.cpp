#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
bool check[5000][5000];
int dp[5000][5000];
int go(int s, int e) {
    if(s > e) return 0;
    if(s == e) return dp[s][e] = 1;
    int &ret = dp[s][e];
    if(ret != -1) return ret;
    
    if(check[s][e]) {
        ret = 2 + go(s + 1, e - 1);
    } else {
        ret = max(go(s + 1, e), go(s, e - 1));
    }
    return ret;
}
int main() {
    fastio;
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            if(a[i] == a[j]) {
                check[i][j] = check[j][i] = true;
            }
        }
    }
    
    memset(dp,-1,sizeof(dp));
    cout << n - go(0, n - 1) << '\n';
    return 0;
}