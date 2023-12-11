#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
vector<ll> tree;
void update(int node, int s, int e, int idx, ll val) {
    if(e < idx || s > idx) return ;
    if(s == e) {
        tree[node] += val;
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
void solve() {
    int n; cin >> n;
    int h = (int)ceil(log2(n));
    tree.clear();
    tree.resize(1 << (h + 1));
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        ans += query(1, 1, n, tmp, n);
        update(1,1,n,tmp,1LL);
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