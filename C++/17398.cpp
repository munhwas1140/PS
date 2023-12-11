#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
int n, m, q;
ll p[100001];
bool check[100001];
vector<pair<int,int>> g;
int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}
void set_union(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return ;
    p[y] += p[x];
    p[x] = y;
}
int main() {
    fastio;
    memset(p,-1,sizeof(p));
    cin >> n >> m >> q;
    g.resize(m + 1);
    for(int i = 1; i <= m; i++) {
        cin >> g[i].first >> g[i].second;
    }
    vector<int> seq(q);
    for(int i = 0; i < q; i ++) {
        cin >> seq[i];
        check[seq[i]] = true;
    }
    
    for(int i = 1; i <= m; i++) {
        if(check[i]) continue;
        set_union(g[i].first, g[i].second); 
    }

    ll ans = 0;
    for(int i = q - 1; i >= 0; i--) {
        int x = g[seq[i]].first;
        int y = g[seq[i]].second;
        if(find(x) != find(y)) {
            ans += p[find(x)] * p[find(y)];
            set_union(x, y);
        }
    }

    cout << ans << '\n';
    return 0;
}