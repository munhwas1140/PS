#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
vector<int> tree;
void update(int idx, int val) {
    for(; idx <= 2 * n; idx += (idx & -idx)) {
        tree[idx] += val;
    }
}
int sum(int idx) {
    int ret = 0;
    for(; idx >= 1; idx -= (idx & -idx)) {
        ret += tree[idx];
    }
    return ret;
}
int main() {
    fastio;
    cin >> n;
    tree.resize(2 * n + 1);
    vector<int> check(n + 1);

    int ans = 0;
    for(int i = 1; i <= 2 * n; i++) {
        int tmp; cin >> tmp;
        if(!check[tmp]) {
            update(i, 1);
            check[tmp] = i;
        } else {
            update(check[tmp], -1);
            ans += sum(i) - sum(check[tmp]);
        }
    }
    cout << ans << '\n';
    return 0;
}