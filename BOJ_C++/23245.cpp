#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
vector<int> tree1, tree2;
vector<pii> a;
void update2(int node, int s, int e, int idx, int val){
    if(idx < s || e < idx) return;
    if(s == e) {
        tree2[node] += val;
    } else {
        int mid = (s + e) / 2;
        update2(node * 2, s, mid, idx, val);
        update2(node * 2 + 1, mid + 1, e, idx, val);
        tree2[node] = tree2[node * 2] + tree2[node * 2 + 1];
    }
}
void update1(int node, int s, int e, int idx, int val) {
    if(idx < s || e < idx) return ;
    if(s == e) {
        tree1[node] += val;
    } else {
        int mid = (s + e) / 2;
        update1(node * 2, s, mid, idx, val);
        update1(node * 2 + 1, mid + 1, e, idx, val);
        tree1[node] = tree1[node * 2] + tree1[node * 2 + 1];
    }
}
ll q1(int node, int s, int e, int l, int r) {
    if(e < l || s > r) return 0LL;
    if(l <= s && e <= r) return ll(tree1[node]);
    int mid = (s + e) / 2;
    ll t1 = q1(node * 2, s, mid, l , r);
    ll t2 = q1(node * 2 + 1, mid + 1, e, l, r);
    return t1 + t2;
}
ll q2(int node, int s, int e, int l, int r) {
    if(e < l || s > r) return 0LL;
    if(l <= s && e <= r) return ll(tree2[node]);
    int mid = (s + e) / 2;
    ll t1 = q2(node * 2, s, mid, l , r);
    ll t2 = q2(node * 2 + 1, mid + 1, e, l, r);
    return t1 + t2;
}  
int main() {
    fastio;
    cin >> n;
    a.resize(n + 1);
    int h = (int)(ceil(log2(1e6 + 1)));
    tree1.resize(1 << (h + 1));
    tree2.resize(1 << (h + 1));
    for(int i = 1; i <= n; i++) {
        cin >> a[i].first;
    }
    for(int i = 1; i <= n; i++) {
        cin >> a[i].second;
        update2(1,0,1e6,a[i].second, 1);
    }
    sort(a.begin() + 1, a.end());
    ll ans = 0;
    // for(int i = 0; i <= 5; i++) {
    //     cout << q2(1,0,1e6,i,1e6) << '\n';
    // }
    for(int i = 1; i <= n; i++) {
        update2(1,0,1e6,a[i].second, -1);
        ll t1 = q1(1,0,1e6,0,a[i].second - 1);
        ll t2 = q2(1,0,1e6,a[i].second + 1, 1e6);
        cout << t1 << ' ' << t2 << '\n';
        ans += t1 * t2;
        update1(1,0,1e6,a[i].second, 1);
    }
    cout << ans << '\n';
    return 0;
}