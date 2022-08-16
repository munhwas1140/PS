#include <bits/stdc++.h>
using namespace std;
vector<int> a;
vector<int> tree[1000000];

// K번째 수

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

// void update(int node, int s, int e, int idx) {
//     if(s > idx || e < idx) return ;
//     tree[node].push_back(a[idx]);
//     if(s != e) {
//         int m = (s + e) >> 1;
//         update(node * 2, s, m, idx);
//         update(node * 2 + 1, m + 1, e, idx);
//     }
// }

int query(int node, int s, int e, int l, int r, int val) {
    if(l > e || s > r) return 0;
    if(l <= s && e <= r) {
        return upper_bound(tree[node].begin(), tree[node].end(), val) - tree[node].begin();
    }
    int m = (s + e) / 2;
    return query(node * 2, s, m, l, r, val) + query(node * 2 + 1, m + 1, e, l, r, val);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    a.resize(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        // update(1,1,n,i);
    }
    init(1,1,n);

    // for(int i = 0; i < 1e6; i++) {
    //     sort(tree[i].begin(), tree[i].end());
    // }

    while(q--) {
        int s, e, k;
        cin >> s >> e >> k;
        int l = -1e9;
        int r = 1e9;
        int ans = 1e9;
        while(l <= r) {
            int m = (l + r) / 2;
            int x = query(1,1,n,s,e,m);
            if(x < k) {
                l = m + 1;
            } else {
                ans = m;
                r = m - 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}