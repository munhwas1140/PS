#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, q;
vector<int> a;
vector<pii> tree;
void init(int node, int s, int e) {
    if(s == e) {
        tree[node] = {a[s], a[e]};
    } else {
        int m = (s + e) / 2;
        init(node * 2, s, m);
        init(node * 2 + 1, m + 1, e);
        tree[node].first = max(tree[node * 2 + 1].first, tree[node * 2].first);
        tree[node].second = min(tree[node * 2 + 1].second, tree[node * 2].second);
    }
}
pii query(int node, int s, int e, int l, int r) {
    if(e < l || s > r) return make_pair(-1, 1e9);
    if(l <= s && e <= r) return tree[node];
    
    int m = (s + e) / 2;
    pii t1 = query(node * 2, s, m, l, r);
    pii t2 = query(node * 2 + 1, m + 1, e, l, r);
    return make_pair(max(t1.first, t2.first), min(t1.second, t2.second));
}
int main() {
    fastio;
    cin >> n >> q;
    a.resize(n + 1);
    int h = (int)ceil(log2(n));
    tree.resize(1 << (h + 1));
    
    for(int i = 1; i <= n; i++) cin >> a[i];

    init(1, 1, n);

    while(q--) {
        int t1, t2;
        cin >> t1 >> t2;
        auto [f, s] = query(1, 1, n, t1, t2);
        cout << f - s << '\n';
    }

    return 0;
}