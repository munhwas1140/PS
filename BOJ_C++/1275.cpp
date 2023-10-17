#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
int n, m;
vector<ll> a;
vector<ll> tree;
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
ll query(int node, int s, int e, int l, int r) {
    if(s > r || e < l) return 0;
    if(l <= s && e <= r) return tree[node];
    int m = (s + e) / 2;
    ll t1 = query(node * 2, s, m, l, r);
    ll t2 = query(node * 2 + 1, m + 1, e, l, r);
    return t1 + t2;
}
void update(int node, int s, int e, int idx, ll val) {
    if(s > idx || e < idx) return;
    if(s == e) tree[node] = val;
    else {
        int m = (s + e) / 2;
        update(node * 2, s, m, idx, val);
        update(node * 2 + 1, m + 1, e, idx, val);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}
int main() {
    fastio;
    cin >> n >> m;
    a.resize(n + 1);
    int h = (int)ceil(log2(n));
    tree.resize(1 << (h + 1));
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }     
    init(1,1,n);
    while(m--) {
        int t1, t2, t3, t4;
        cin >> t1 >> t2 >> t3 >> t4;
        if(t1 > t2) swap(t1, t2);
        cout << query(1,1,n,t1,t2) << '\n';
        update(1,1,n,t3,ll(t4));
    }
      
    return 0;
}