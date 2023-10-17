#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int MAX_SZ = 1e5 + 10;

struct Node {
    Node *l, *r;
    int val;
    Node () : l(nullptr), r(nullptr) , val(0) {
    }
};

void add(Node *node, int s, int e, int idx, int val) {
    

}

int query(Node *node, int s, int e, int l, int r) {
    if(r < s || e < l) return 0;
    if(l <= s && e <= r) return node->val;
    int m = (s + e) / 2;
    int t1 = query(node->l, s, m, l, r);
    int t2 = query(node->r, m + 1, e, l, r);
    return t1 + t2;
}

int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> p(MAX_SZ, vector<int>());
        for(int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            x++; y++;
            p[x].push_back(y);
        }
        vector<Node *> tree[MAX_SZ];
        tree[0] = new Node();
        for(int i = 1; i < MAX_SZ; i++) {
            t[i] = t[i - 1];
            for(auto &y : p[i]) {
                add(tree[i], 1, MAX_SZ, y, 1);
            }
        }

        ll ans = 0;

        for(int i = 0; i < m; i++) {
            int l, r, b, u;
            cin >> l >> r >> b >> u;
            l++; r++; b++; u++;
            ans += query(tree[r], 1, MAX_SZ, b, u);
            ans -= query(tree[l - 1], 1, MAX_SZ, b, u);
        }
        cout << ans << '\n';

    }
    return 0;
}