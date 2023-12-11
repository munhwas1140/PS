#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
int n, m, SCCcnt;
int a[100001];
vector<int> swc[100001];
vector<int> g[200002], gp[200002], order;
int SCC[200002];
bool visited[200002];
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
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    for(int i = 0; i < m; i++) {
        int k; cin >> k;
        for(int j = 0; j < k; j++) {
            int tmp; cin >> tmp;
            swc[tmp].push_back(i);
        }
    }

    
    for(int i = 1; i <= n; i++) {
        int t1 = swc[i][0];
        int t2 = swc[i][1];
        t1 *= 2;
        t2 *= 2;
        int nt1 = t1 + 1;
        int nt2 = t2 + 1;
        if(a[i]) {
            g[t1].push_back(t2);
            g[t2].push_back(t1);
            g[nt1].push_back(nt2);
            g[nt2].push_back(nt1);
            gp[t1].push_back(t2);
            gp[t2].push_back(t1);
            gp[nt1].push_back(nt2);
            gp[nt2].push_back(nt1);
        } else {
            g[t1].push_back(nt2);
            g[t2].push_back(nt1);
            g[nt1].push_back(t2);
            g[nt2].push_back(t1);
            gp[t1].push_back(nt2);
            gp[t2].push_back(nt1);
            gp[nt1].push_back(t2);
            gp[nt2].push_back(t1);
        }
    }

    for(int i = 0; i < 2 * m; i++) {
        if(!visited[i]) dfs(i);
    }

    memset(visited,false,sizeof(visited));
    reverse(order.begin(), order.end());
    
    for(int &i : order) {
        if(!SCC[i]) dfs_rev(i, ++SCCcnt);
    }

    bool ok = true;
    for(int i = 0; i < m; i++) {
        if(SCC[i * 2] == SCC[i * 2 + 1]) {
            ok = false; break;
        }
    }

    cout << ok << '\n';
    return 0;
}