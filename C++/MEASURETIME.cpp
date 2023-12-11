#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
ll tree[1000001];
void update(int idx, int val) {
    for(; idx <= 1000000; idx += (idx & -idx)) {
        tree[idx] += val;
    }
}
ll query(int idx) {
    ll sum = 0;
    for(; idx > 0; idx &= (idx - 1)) {
        sum += tree[idx];
    }
    return sum;
}
void solve() {
    cin >> n;
    memset(tree,0,sizeof(tree));

    ll tmp,ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        tmp++;
        ans += query(1000000) - query(tmp);
        update(tmp, 1);
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