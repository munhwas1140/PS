#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
vector<int> tree;
vector<int> a;
void init(int node, int s, int e) {
    if(s == e) {
        tree[node] = a[s];
    } else {
        int mid = (s + e) / 2;
        init(node * 2, s, mid);
        init(node * 2 + 1, mid + 1, e);
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }
}
int query(int node, int s, int e, int l, int r) {
    if(e < l || s > r) return 1e9;
    if(l <= s && e <= r) return tree[node];
    int mid = (s + e) / 2;
    int t1 = query(node * 2, s, mid, l, r);
    int t2 = query(node * 2 + 1, mid + 1, e, l, r);
    return min(t1, t2);
}
int main() {
    fastio;
    cin >> n >> m;
    a.resize(m + 1);
    for(int i = 1; i <= m; i++) {
        cin >> a[i];
        a[i] = n - a[i];
    }

    int h = (int)ceil(log2(m + 1));
    tree.resize(1 << (h + 1));
    init(1, 1, m);
    int q; cin >> q;
    while(q--) {
        int x1, y1, x2, y2, k;
        cin >> x1 >> y1 >> x2 >> y2 >> k;
        x1 = n - x1;
        x2 = n - x2;
        if(abs(x1 - x2) % k || abs(y1 - y2) % k || x1 > a[y1] || x2 > a[y2]) cout << "NO" << '\n';
        else {
            int tmp = x1 % k;
            if(y1 > y2) swap(y1, y2);
            int q = query(1, 1, m, y1, y2);
            if(q > tmp) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        }
    }
    return 0;
}