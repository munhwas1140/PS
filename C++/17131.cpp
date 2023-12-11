#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int mod = 1e9 + 7;
const int MAX = 4e5 + 2;
int n;
vector<pii> a;
void update(vector<int> &tree, int node, int s, int e, int idx, int val) {
    if(idx < s || e < idx) return;
    if(s == e) {
        tree[node] += val;
        return ;
    }
    int m = (s + e) / 2;
    update(tree, node * 2, s, m, idx, val);
    update(tree, node * 2 + 1, m + 1, e, idx, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
ll query(vector<int> tree, int node, int s, int e, int l, int r) {
    if(e < l || r < s) return 0LL;
    if(l <= s && e <= r) return (ll)(tree[node]);
    int m = (s + e) / 2;
    ll t1 = query(tree, node * 2, s, m, l, r);
    ll t2 = query(tree, node * 2 + 1, m + 1, e, l, r);
    return t1 + t2;
}
int main() {
    fastio;
    vector<int> ltree, rtree;
    cin >> n;
    a.resize(n + 1);
    int h = (int)ceil(log2(MAX + 1));
    ltree.resize(1 << (h + 1));
    rtree.resize(1 << (h + 1));
    for(int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
        a[i].second += 200000;
        update(rtree,1,0,MAX,a[i].second,1);
    }
    
    sort(a.begin() + 1, a.end());
    
    ll ans = 0;
    for(int i = 1; i <= n; i++) { 
        int s, e;
        s = e = i;
        while(e < n && a[e].first == a[e + 1].first) e++;
        for(int j = s; j <= e; j++) {
            update(rtree, 1, 0, MAX, a[j].second, -1);
        }
        for(int j = s; j <= e; j++) {
            ll t1 = query(ltree, 1, 0, MAX, a[j].second + 1, MAX);
            ll t2 = query(rtree, 1, 0, MAX, a[j].second + 1, MAX);
            ans += t1 * t2;
            ans %= mod;
        }
        for(int j = s; j <= e; j++) {
            update(ltree, 1, 0, MAX, a[j].second, 1);
        }
        i = e;
    }
    cout << ans << '\n';
    return 0;
}