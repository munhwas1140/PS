#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, k;
const int MOD = 5000000;
vector<vector<int>> tree;
void update(int node, int s, int e, int idx, vector<int> &tv) {
    if(e < idx || s > idx) return;
    if(s == e) {
        for(int i = 1; i < k; i++) {
            tree[node][i] += tv[i - 1];
            tree[node][i] %= MOD;
        }
        tree[node][0]++;
        tree[node][0] %= MOD;
        return ;
    }
    int m = (s + e) / 2;
    update(node * 2, s, m, idx, tv);
    update(node * 2 + 1, m + 1, e, idx, tv);
    for(int i = 0; i < k; i++) {
        tree[node][i] = tree[node * 2][i] + tree[node * 2 + 1][i];
        tree[node][i] %= MOD;
    }
}
vector<int> query(int node, int s, int e, int l, int r) {
    if(e < l || s > r) return vector<int>(k);
    if(l <= s && e <= r) return tree[node];
    int mid = (s + e) / 2;
    auto t1 = query(node * 2, s, mid, l, r);
    auto t2 = query(node * 2 + 1, mid + 1, e, l, r);
    for(int i = 0; i < k; i++) {
        t1[i] += t2[i];
        t1[i] %= MOD;
    }
    return t1;
}
int main() {
    fastio;
    cin >> n >> k;
    int h = (int)ceil(log2(n));
    tree = vector<vector<int>>(1 << (h + 1), vector<int>(k));
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        auto tv = query(1, 1, n, 1, tmp - 1);
        ans += tv[k - 2];
        ans %= 5000000;
        update(1, 1, n, tmp, tv);
    }

    cout << ans << '\n';

    return 0;
}