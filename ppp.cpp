#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
ll ans = 0;
vector<int> a;
vector<pair<int,int>> tree;
void init() {
    a.clear();
    tree.clear();
    ans = 0;
}
void init(int node, int s, int e) {
    if(s == e) {
        tree[node] = make_pair(a[s], a[e]);
        ans += 1LL;
        return ;
    } else {
        int m = (s + e) / 2;
        init(node * 2, s, m);
        init(node * 2 + 1, m + 1, e);
        tree[node].first = min(tree[node*2].first, tree[node * 2 + 1].first);
        tree[node].second = max(tree[node * 2].second, tree[node * 2 + 1].second);
        if(tree[node].second % tree[node].first == 0) {
            ans += 1LL;
        }
    }
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        init();
        int n; cin >> n;
        a.resize(n + 1);
        int h = (int)ceil(log2(n));
        tree.resize(1 << (h + 1));
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        init(1,1,n);
        cout << ans << '\n';

    }
    return 0;
}