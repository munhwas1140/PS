#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
vector<int> tree;
int cnt[75001];
void init(int node, int s, int e) {
    if(s == e) {
        tree[node] = cnt[s];
    } else {
        int m = (s + e) / 2;
        init(node * 2, s, m);
        init(node * 2 + 1, m + 1, e);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}
void update(int node, int s, int e, int idx, int val) {
    if(e < idx || s > idx) return;
    if(s == e) {
        tree[node] += val;
        return ;
    }
    int m = (s + e) / 2;
    update(node * 2, s, m, idx, val);
    update(node * 2 + 1, m + 1, e, idx, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
ll query(int node, int s, int e, int l, int r) {
    if(s > r || e < l) return 0LL;
    if(l <= s && e <= r) {
        return (ll)tree[node];
    }

    int m = (s + e) / 2;
    ll t1 = query(node * 2, s, m, l, r);
    ll t2 = query(node * 2 + 1, m + 1, e, l, r);
    return t1 + t2;
}
void solve() {
    int n; cin >> n;
    int h = (int)ceil(log2(75000));
    tree.resize(1 << (h + 1));
    vector<pii> a(n);
    vector<int> aa(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        aa[i] = a[i].first;
    }

    sort(aa.begin(), aa.end());
    aa.erase(unique(aa.begin(), aa.end()), aa.end());
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < n; i++) {
        a[i].first = lower_bound(aa.begin(), aa.end(), a[i].first) - aa.begin();
        cnt[a[i].first]++;
    }
    
    sort(a.begin(), a.end(), [](auto &u, auto &v) {
        if(u.second == v.second) {
            return u.first < v.first;
        }
        return u.second > v.second;
    });
    init(1,0,75000);
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        update(1,0,75000,a[i].first, -1);
        ans += query(1,0,75000,a[i].first, 75000);
    }
    cout << ans << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}