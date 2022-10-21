#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1e9 + 7;
string str, e;
int n, m;
int dp[1<<14][20][2];
int price(int idx, int taken, int mod, int less) {
    if(idx == n) {
        return (less && mod == 0) ? 1 : 0;
    }

    int &ret = dp[taken][mod][less];
    if(ret != -1) return ret;
    ret = 0;
    for(int next = 0; next < n; next++) {
        if((taken & (1<<next)) == 0) {
            if(!less && e[idx] < str[next]) {
                continue;
            }
        }
        if(next > 0 && str[next - 1] == str[next] && (taken & ( 1 << (next - 1))) == 0) {
            continue;
        }

        int nextTaken = taken | (1 << next);
        int nextMod = (mod * 10 + str[next] - '0') % m; 
        int nextLess = less | (e[idx] > str[next]);
        ret += price(idx + 1, nextTaken, nextMod, nextLess);
        ret %= MOD;
    }
    return ret;
}
void solve() {
    cin >> str >> m;
    e = str;
    memset(dp,-1,sizeof(dp));
    sort(e.begin(), e.end());
    cout << price(0, 0, m, 0) << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}