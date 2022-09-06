#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
int n, q;
vector<ll> tree;
void update(int node, int s, int e, int idx, ll val) {
    if(idx < s || e < idx) return; 
    if(s == e) {
        tree[node] += val;
        return ;
    }
    int m = (s + e) / 2;
    update(node * 2, s, m, idx, val);
    update(node * 2 + 1, m + 1, e, idx, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
ll query(int node, int s, int e, int l, int r) {
    if(s > r || e < l) return 0;
    if(l <= s && e <= r) return tree[node];
    
    int m = (s + e) / 2;
    ll t1 = query(node * 2, s, m, l, r);
    ll t2 = query(node * 2 + 1, m + 1, e, l, r);
    return t1 + t2;
}
int main() {
    fastio;
    cin >> n >> q; 
    int h = (int)ceil(log2(n));
    tree.resize(1 << (h + 1));
    while(q--) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        if(t1 == 1) {
            update(1,1,n,t2,ll(t3));
        } else {
            cout << query(1,1,n,t2,t3) << '\n';
        }
    }

    return 0;
}