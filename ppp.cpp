#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, k;
vector<int> g[200001];
int dfs(int now, int dep,int mid) {
    int ret = 0;
    if(dep > mid) {
        dep = 1;
        ret++;
    }
    for(int &next : g[now]) {
        ret += dfs(next, dep + 1, mid);
    }
    return ret;
}
int check(int mid) {
    return dfs(1,0,mid);
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        for(int i = 0; i < 200001; i++) {
            g[i].clear();
        }
        cin >> n >> k;
        for(int i = 2; i <= n; i++) {
            int tmp;
            cin >> tmp;
            g[tmp].push_back(i);
        }

        int l = 1, r = 2e5+1;
        int ans = 1;
        while(l <= r) {
            int m = (l + r) / 2;
            if(check(m) <= k) {
                ans = m;
                r = m - 1;    
            } else l = m + 1;
        }
        cout << ans << '\n';
    }

    return 0;
}