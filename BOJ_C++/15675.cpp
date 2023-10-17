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
vector<string> a;
vector<int> g[8080], gp[8080], order;
int SCC[8080];
bool visited[8080];
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
    a.resize(n);
    vector<pii> jewel;
    vector<pii> danger;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j = 0; j < m; j++) {
            if(a[i][j] == '*') {
                jewel.push_back({i, j});
            } else if(a[i][j] == '#') {
                danger.push_back({i, j});
            }
        }
    }
    
    // r % 2 == 0, c % 2 == 1;
    for(auto &[x, y] : jewel) {
        x *= 2;
        y *= 2;
        y += 2 * n; 
        // (x v y) ^ (~x v ~y)
        int notx = x + 1;
        int noty = y + 1;
        g[notx].push_back(y);
        g[noty].push_back(x);
        g[x].push_back(noty);
        g[y].push_back(notx);
        gp[notx].push_back(y);
        gp[noty].push_back(x);
        gp[x].push_back(noty);
        gp[y].push_back(notx);
    }

    for(auto &[x, y] : danger) {
        x *= 2;
        y *= 2;
        y += 2 * n;
        //(~x v y) ^ (x v ~y)
        int notx = x + 1;
        int noty = y + 1;
        g[x].push_back(y);
        g[noty].push_back(notx);
        g[notx].push_back(noty);
        g[y].push_back(x);
        gp[x].push_back(y);
        gp[noty].push_back(notx);
        gp[notx].push_back(noty);
        gp[y].push_back(x);
    }

    //SCC 
    for(int i = 0; i < 2 * (n + m); i++) {
        if(!visited[i]) dfs(i);
    }
    
    memset(visited,false,sizeof(visited));
    reverse(order.begin(), order.end());

    for(int &i : order) {
        if(!SCC[i]) dfs_rev(i, ++SCCcnt);
    }
    
    bool ok = true;
    for(int i = 0; i < n + m; i++) {
        if(SCC[i * 2] == SCC[i * 2 + 1]) ok = false;
    }
    
    cout << ok << '\n';
    return 0;
}