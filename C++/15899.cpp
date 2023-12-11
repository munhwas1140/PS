#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1e9 + 7;
int n, m, c;
int a[200001];
vector<int> g[200001];
vector<vector<int>> tree;
bool visited[200001];
int gg[400002];
int gin[400002];
int gout[400002];
int cnt = 0;
void init(int node, int s, int e) {
    if(s == e) {
        if(gg[s] == 0) return ;
        tree[node].push_back(a[gg[s]]);
        return ;
    }
    int m = (s + e) >> 1;
    init(node * 2, s, m);
    init(node * 2 + 1, m + 1, e);
    merge(tree[node*2].begin(), tree[node*2].end(), tree[node*2+1].begin(), tree[node*2+1].end(), back_inserter(tree[node]));
}
int query(int node, int s, int e, int l, int r, int k) {
    if(e < l || s > r) return 0;
    if(l <= s && e <= r) {
        return  upper_bound(tree[node].begin(),tree[node].end(),k) - tree[node].begin();
    }
    int m = (s + e) >> 1;
    return query(node * 2, s, m, l, r, k) + query(node * 2 + 1, m + 1, e, l, r, k);
}
void dfs(int now) {
    visited[now] = true;
    gin[now] = ++cnt;
    gg[cnt] = now;
    for(int &next : g[now]) {
        if(!visited[next]) {
            dfs(next);
        }
    }
    gout[now] = ++cnt;
}
int main() {
    fastio;
    cin >> n >> m >> c;

    int h = (int)ceil(log2(2 * n + 1));
    tree.resize(1 << (h + 1));

    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 0; i < n - 1; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }

    dfs(1);
    init(1,1,2 * n);
    
    int ans = 0;
    for(int i = 0; i < m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        int tmp = query(1,1,2 * n, gin[t1], gout[t1], t2);
        ans += query(1,1,2 * n,gin[t1], gout[t1], t2);
        ans %= MOD;
    }
    cout << ans << '\n';

    return 0;
}