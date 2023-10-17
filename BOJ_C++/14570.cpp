#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
vector<int> g[200001];
int dfs(int now, ll k) {
    int sz = g[now].size();
    if(sz == 1) {
        return dfs(g[now][0], k);
    } else if(sz == 2) {
        if(k % 2) {
            return dfs(g[now][0], (k + 1) / 2);
        } else {
            return dfs(g[now][1], k / 2);
        }
    } else {
        return now;
    }
}
int main() {
    fastio;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        if(t1 != -1) g[i].push_back(t1);
        if(t2 != -1) g[i].push_back(t2);
    }
    
    ll k; cin >> k;
    cout << dfs(1, k) << '\n';
    return 0;
}