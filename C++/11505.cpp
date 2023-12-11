#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
int n, m, k;
vector<ll> a;
vector<ll> tree;
const ll mod = 1e9 + 7;
void init(int node, int l, int r) {
    if(l == r) {
        tree[node] = a[l];
    } else {
        int m = (l + r) >> 1;
        init(node * 2, l, m);
        init(node * 2 + 1, m + 1, r);
        tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % mod;
    }
}
void update(int node, int l, int r, int idx, ll val) {
    if(idx < l || idx > r) return;
    if(l == r) {
        tree[node] = val;
        return ;
    }
    int m = (l + r) / 2;
    update(node * 2, l, m, idx, val);
    update(node * 2 + 1, m + 1, r, idx, val);
    tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % mod;
}
ll query(int node, int l, int r, int s, int e) {
    if(l > e || s > r) return 1;
    if(s <= l && r <= e) return tree[node];
    int m = (l + r) / 2;
    
    ll t1 = query(node * 2, l, m, s, e);
    ll t2 = query(node * 2 + 1, m + 1, r, s, e);
    return (t1 * t2) % mod;
}
int main() {
    fastio;
    cin >> n >> m >> k;
    m += k;
    a.resize(n + 1);
    int h = (int)ceil(log2(n));
    tree.resize(1 << (h + 1));
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }         
    init(1,1,n);
    
    while(m--) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        if(t1 == 1) {
            update(1,1,n,t2,(ll)(t3));
        } else {
            cout << query(1,1,n,t2,t3) << '\n';
        }
    }
    return 0;
}