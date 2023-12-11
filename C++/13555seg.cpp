#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, k;
const int MOD = 5000000;
int a[100001];
int dp[100001][51];
int tree[51][400000];
void update(int node, int s, int e, int idx, int val, int sz) {
    if(e < idx || s > idx) return;
    if(s == e) {
        tree[sz][node] += val;
        tree[sz][node] %= MOD;
    } else {
        int mid = (s + e) / 2;
        update(node * 2, s, mid, idx, val, sz);
        update(node * 2 + 1, mid + 1, e, idx, val, sz);
        tree[sz][node] = (tree[sz][node * 2] + tree[sz][node * 2 + 1]) % MOD;
    }
}
int sum(int node, int s, int e, int l, int r, int sz) {
    if(sz == 0) return 1;

    if(e < l || s > r) return 0;
    if(l <= s && e <= r) return tree[sz][node];
    
    int mid = (s + e) / 2;
    int t1 = sum(node * 2, s, mid, l, r, sz);
    int t2 = sum(node * 2 + 1, mid + 1, e, l, r, sz);
    return (t1 + t2) % MOD;
}
int main() {
    fastio;
    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            dp[i][j] = sum(1, 1, 100000, 1, a[i] - 1, j - 1);
            update(1, 1, 100000, a[i], dp[i][j], j);
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += dp[i][k];
        ans %= MOD;
    }
    cout << ans << '\n';


    return 0;
}