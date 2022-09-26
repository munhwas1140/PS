#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
int n, m;
vector<int> g[20000];
vector<int> gp[20000];
vector<int> order;
bool visited[20000];
int SCC[20000];
int SCCcnt;
int neg(int now) {
    return (now % 2 ? now - 1 : now + 1);
}
void dfs(int now) {
    visited[now] = true;
    for(int &next : g[now]) {
        if(!visited[next]) dfs(next);
    }
    order.push_back(now);
}
void dfs_rev(int now, int num) {
    visited[now] = true;
    SCC[now] = num;
    for(int &next : gp[now]) {
        if(!visited[next]) dfs_rev(next, num);
    }
}
int main() {
    fastio;
    cin >> m >> n; 
    for(int i = 0; i < m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        t1 = (t1 < 0 ? -(t1 + 1) * 2 + 1 : (t1 - 1) * 2);
        t2 = (t2 < 0 ? -(t2 + 1) * 2 + 1 : (t2 - 1) * 2);
        int nt1 = neg(t1);
        int nt2 = neg(t2);
        g[nt1].push_back(t2);
        g[nt2].push_back(t1);
        gp[t2].push_back(nt1);
        gp[t1].push_back(nt2);
    }
    
    for(int i = 0; i < 2 * n; i++) {
        if(!visited[i]) dfs(i);
    }

    memset(visited,false,sizeof(visited));
    reverse(order.begin(), order.end());
    
    for(int &i : order) {
        if(!SCC[i]) {
            dfs_rev(i, ++SCCcnt);
        }
    }
    bool ok = true;
    for(int i = 0; i < n; i++) {
        if(SCC[i * 2] == SCC[i * 2 + 1]) {
            ok = false;
            break;
        }
    }
    cout << (ok ? "^_^" : "OTL") << '\n';
    return 0;
}