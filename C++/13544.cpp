#include <bits/stdc++.h>
using namespace std;
vector<int> a;
vector<vector<int>> tree;

// 수열과 쿼리3

void init(int node, int s, int e) {
    if(s == e) {
        tree[node].push_back(a[s]);
    } else {
        int m = (s + e) / 2;
        init(node * 2, s, m);
        init(node * 2 + 1, m + 1, e);
        for(int x : tree[node * 2]) tree[node].push_back(x);
        for(int x : tree[node * 2 + 1]) tree[node].push_back(x);
        sort(tree[node].begin(), tree[node].end());
    }
}

int query(int node, int s, int e, int l, int r, int k) {
    if(e < l || r < s) return 0;
    if(l <= s && e <= r) {
        return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), k);
    }
    int m = (s + e) / 2;
    int t1 = query(node * 2, s, m, l, r, k);
    int t2 = query(node * 2 + 1, m + 1, e, l, r, k);
    return t1 + t2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    
    a.resize(n + 1);
    int h = (int)ceil(log2(n));
    tree.resize(1 << (h + 1));

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    init(1,1,n);
    
    int q;
    cin >> q;
    int ans = 0;
    while(q--) {
        int i, j, k;
        cin >> i >> j >> k;
        i ^= ans;
        j ^= ans;
        k ^= ans;
        cout << (ans = query(1,1,n,i,j,k)) << '\n';
    }
    return 0;
}