#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
vector<int> tree;
vector<int> check;
struct asdf {
    int x, y1, y2, val;
};
void update(int node, int s, int e, int l, int r, int val) {
    if(s > r || e < l) return ;
    if(l <= s && e <= r) {
        check[node] += val;
    } else {
        int m = (s + e) / 2;
        update(node * 2, s, m, l, r, val);
        update(node * 2 + 1, m + 1, e, l, r, val);
    }
    if(check[node]) tree[node] = e - s + 1;
    else {
        if(s == e) tree[node] = 0;
        else {
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }
}
int main() {
    fastio;
    int n; cin >> n;
    vector<asdf> a;
    for(int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a.push_back({x1,y1,y2-1,1});
        a.push_back({x2,y1,y2-1,-1});
    }

    sort(a.begin(), a.end(), [] (const asdf &u, const asdf &v) {
        return u.x < v.x;
    });

    int h = (int)ceil(log2(30001));
    tree.resize(1 << (h + 1));
    check.resize(1 << (h + 1));
    
    int pre = 0;
    ll ans = 0;
    for(auto &[x, y1, y2, val] : a) {
        ans += (ll)(x - pre) * tree[1];
        update(1,0,30000,y1,y2, val);
        pre = x;
    }
    cout << ans << '\n';

    return 0;
}