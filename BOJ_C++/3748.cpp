#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m, cnt;
int dfsn[100001], low[100001], par[100001];
bool visited[100001];
vector<int> g[100001];
vector<int> pos;
void dfs(int now) {
    dfsn[now] = ++cnt;
    low[now] = cnt;
    int sub = 0;
    for(int next : g[now]) {
        if(par[now] == next) continue;

        if(!dfsn[next]) {
            sub++;
            par[next] = now;
            dfs(next);
            
            if(!par[now] && sub > 1) pos.push_back(now);
            else if(par[now] && low[next] >= dfsn[now]) pos.push_back(now);
            
            low[now] = min(low[now], low[next]);

        } else {
            low[now] = min(low[now], dfsn[next]);
        }

    }
    
}

int t;
bool dfs2(int now, int s) {
    cout << now << ' ';
    visited[now] = true;
    t++;
    for(int next : g[now]) {
        if(!visited[next]) {
            if(dfs2(next, s)) return true;
        } else if(next == s) return true;
    }
    visited[now] = false;
    return false;
}
void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }

    for(int i = 1; i <= n; i++) {
        if(!dfsn[i]) dfs(i);
    }

    sort(pos.begin(), pos.end());
    pos.erase(unique(pos.begin(), pos.end()), pos.end());
    

    int ans = 0;
    for(int x : pos) {
        bool ok = false;
        while(true) {
            t = 0;
            dfs2(x, x);
            cout << ' ' << t << '\n';
            if(t == 1) break;
            else {
                if(t % 2) {
                    ans += t - 1;
                    ok = true;
                } 
                visited[x] = false;
            }
        }
        ans += ok;
    }
    cout << ans << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}