#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 9999991;
struct node {
    node *l, *r;
    int v, sz = 0;
    node () : l(nullptr), r(nullptr) {}
};

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
void solve() {
    for(int i = 1; i <= 20; i++) g[i].clear();
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
        if(now->l != nullptr) {
            g[now->v].push_back(now->l->v);
            dfs(now->l);
        }
        if(now->r != nullptr) {
            g[now->v].push_back(now->r->v);
            dfs(now->r);
        }
    };
    dfs(tree);

    vector<bool> check(21,false);
    

    function<int(int, int)> go = [&] (int now, int idx) {
        if(idx == n) return 1;
        int ret = 0;

        for(int next : g[now]) {
            check[next] = true;
        }

        for(int i = 1; i <= n; i++) {
            if(check[i]) {
                check[i] = false;
                ret += go(i, idx + 1);
                ret %= MOD;
                check[i] = true;
            }
        }
        for(int next : g[now]) {
            check[next] = false;
        }
        return ret;
    };
    
    cout << go(tree->v, 1) << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}