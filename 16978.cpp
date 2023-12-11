#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
vector<ll> tree;
ll a[1000001];
void init(int node, int s, int e) {
    if(s == e) {
        tree[node] = a[s];
    } else {
        int m = (s + e) / 2;
        init(node * 2, s, m);
        init(node * 2 + 1, m + 1, e);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}
void update(int node, int s, int e, int idx, ll val) {
    if(e < idx || s > idx) return;
    if(s == e) {
        tree[node] = val;
    } else {
        int m = (s + e) / 2;
        update(node * 2, s, m, idx, val);
        update(node * 2 + 1, m + 1, e, idx, val);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}
ll query(int node, int s, int e, int l, int r) {
    if(e < l || s > r) return 0LL;
    if(l <= s && e <= r) return tree[node];
    
    int m = (s + e) / 2;
    ll t1 = query(node * 2, s, m, l, r);
    ll t2 = query(node * 2 + 1, m + 1, e, l, r);
    return t1 + t2;
}
int main() {
    fastio;
    int n; cin >> n;
    int h = (int)ceil(log2(n));
    tree.resize(1 << (h + 1));
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    init(1,1,n);
    int m; cin >> m;
    vector<pii> u;
    vector<tuple<int,int,int,int>> q;
    int it = 0;
    for(int i = 0; i < m; i++) {
        int op; cin >> op;
        if(op == 1) {
            int t1, t2;
            cin >> t1 >> t2;
            u.push_back({t1, t2});
        } else {
            int t1, t2, t3;
            cin >> t1 >> t2 >> t3;
            q.push_back({t1, t2, t3,it++});
        }
    }
    sort(q.begin(), q.end());
    int idx = 0;
    vector<ll> ans(it);
    for(auto &[num, l, r, tmp] : q) {
        while(num != idx) {
            update(1,1,n, u[idx].first, (ll)u[idx].second);
            idx++;
        }
        ans[tmp] = query(1,1,n,l,r);
    }
    for(int i = 0; i < it; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}