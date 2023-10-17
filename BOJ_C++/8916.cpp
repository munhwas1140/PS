#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 9999991;
struct node {
    node *l, *r;
    int v;
    node () : l(nullptr), r(nullptr) {}
};
ll f[21];

node *insert(node *tree, int val) {
    if(tree == nullptr) {
        node *tmp = new node();
        tmp->v = val;
        return tmp;
    }

    if(tree->v < val) {
        tree->r = insert(tree->r, val);
    } else {
        tree->l = insert(tree->l, val);
    }
    return tree;
}
vector<int> g[21];
int sz[21];
void solve() {
    for(int i = 1; i <= 20; i++) g[i].clear();
    memset(sz, 0, sizeof(sz));
    int n; cin >> n;
    node *tree = new node();
    for(int i = 0; i < n; i++) {
        int t; cin >> t;
        if(i == 0) {
            tree->v = t;
        } else {
            insert(tree, t);
        }
    }

    function<void(node *)> dfs = [&] (node *now) {
        sz[now->v] = 1;
        if(now->l != nullptr) {
            g[now->v].push_back(now->l->v);
            dfs(now->l);
            sz[now->v]++;
        }
        if(now->r != nullptr) {
            g[now->v].push_back(now->r->v);
            dfs(now->r);
            sz[now->v]++;
        }
    };
    dfs(tree);

    vector<bool> check(21,false);
    function<int(int, int)> go = [&] (int now, int idx) {
        
    }


    cout << go(tree->v, 1) << '\n';
}

int main() {
    f[0] = 1;
    f[1] = 1;
    for(int i = 2; i <= 20; i++) {
        f[i] = f[i - 1] * (ll)i;
    }
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}