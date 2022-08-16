#include <bits/stdc++.h>
using namespace std;
vector<int> a;
vector<vector<int>> tree;

void init(int node, int s, int e) {
    if(s == e) {
        tree[node].push_back(a[s]);
    } else {
        int m = (s + e) >> 1;
        init(node * 2, s, m);
        init(node * 2 + 1, m + 1, e);
        for(int x : tree[node * 2]) tree[node].push_back(x);
        for(int x : tree[node * 2 + 1]) tree[node].push_back(x);
        sort(tree[node].begin(), tree[node].end());
    }
}

int query(int node, int s, int e, int l, int r, int x) {
    if(e < l || s > r) return 0;
    if(l <= s && e <= r) {
        return upper_bound(tree[node].begin(), tree[node].end(), x) - tree[node].begin();
    }
    int m = (s + e) >> 1;
    int t1 = query(node * 2, s, m, l, r, x);
    int t2 = query(node * 2 + 1, m + 1, e, l, r, x);
    return t1 + t2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    a.resize(n + 1);
    int h = (int)ceil(log2(n));
    tree.resize(1 << (h + 1));
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    init(1,1,n);

    while(q--) {
        int s, e, k;
        cin >> s >> e >> k;
        int l = -1e9;
        int r = 1e9;
        int ans = 1e9 + 7;
        while(l <= r) {
            int m = (l + r) >> 1;
            if(query(1,1,n,s,e,m) >= k) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}