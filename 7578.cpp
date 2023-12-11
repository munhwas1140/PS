#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
vector<int> tree;
int cache[1000001];
void update(int node, int s, int e, int idx) {
    if(idx > e || idx < s) return ;
    if(s == e) {
        tree[node] = 1;
        return ;
    }
    int m = (s + e) / 2;
    update(node * 2, s, m, idx);
    update(node * 2 + 1, m + 1, e, idx);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int query(int node, int s, int e, int l, int r) {
    if(e < l || e > r) return 0;
    if(l <= s && e <= r) return tree[node];
    int m = (s + e) / 2;
    int t1 = query(node * 2, s, m, l, r);
    int t2 = query(node * 2 + 1, m + 1, e, l, r);
    return t1 + t2;
}
int main() {
    fastio;
    int n; cin >> n;
    int h = (int)ceil(log2(n + 1));
    tree.resize(1 << (h + 1));
    
    for(int i = 1; i <= n; i++) {
        int tmp; cin >> tmp;
        cache[tmp] = i;
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        update(1,1,n,cache[tmp]);
        ans += (ll)query(1,1,n,cache[tmp] + 1, n);
    }
    cout << ans << '\n';
    return 0;
}