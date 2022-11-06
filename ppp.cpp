#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
vector<int> a, tree;
void init(int node, int s, int e) {
    if(s == e) {
        tree[node] = a[s];
    } else {
        int m = (s + e) / 2;
        init(node * 2, s, m);
        init(node * 2, m + 1, e);
        tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
    }
}
void solve() {
    int n, q;
    cin >> n >> q;
    a.resize(n);
    int h = (int)ceil(log2(n + 1));
    tree.resize(1 << (h + 1));
    for(int i = 1; i <= n; i++) cin >> a[i];
    init(1, 1, n);

    while(q--) {
        int l, r;
        cin >> l >> r;
        if((r - l + 1) % 2 == 0) {
            if(a[l] == 0) {

            } else if(a[r] == 0) {

            } else {
                cout << -1 << '\n';
            }
        } else {

        }
        

    }
}
int main() {
    fastio;
    solve();
    return 0;
}