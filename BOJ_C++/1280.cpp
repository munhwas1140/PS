#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
const int _max = 2e5 + 1;
const ll mod = 1e9 + 7;
int n;
vector<pair<ll,ll>> tree;
void update(int node, int s, int e, ll idx) {
    if(idx < s || e < idx) return ;
    if(s == e) {
        tree[node].first += idx;
        tree[node].second += 1;
    } else {
        int m = (s + e) / 2;
        update(node * 2, s, m, idx);
        update(node * 2 + 1, m + 1, e, idx);
        tree[node].first = tree[node * 2].first + tree[node * 2 + 1].first;
        tree[node].second = tree[node * 2].second + tree[node * 2 + 1].second;
    }
}
pair<ll,ll> query(int node, int s, int e, int l, int r) {
    if(e < l || s > r) return make_pair(0, 0);
    if(l <= s && e <= r) return tree[node];
    int m = (s + e) / 2;
    auto t1 = query(node * 2, s, m, l, r);
    auto t2 = query(node * 2 + 1, m + 1, e, l, r);
    return make_pair(t1.first + t2.first, t1.second + t2.second); 
} 
int main() {
    fastio;
    cin >> n;
    int h = (int)ceil(log2(_max));
    tree.resize(1 << (h + 1));

    ll ans = 1, tmp; 
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        auto t1 = query(1,0,_max,0,tmp-1);
        auto t2 = query(1,0,_max,tmp+1,_max);
        if(i) ans *= ((tmp * t1.second - t1.first) + (t2.first - tmp * t2.second)) % mod;
        ans %= mod; 
        update(1,0,_max,tmp);
    }
    cout << ans << '\n';
      
    return 0;
}