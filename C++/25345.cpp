#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9 + 7;
ll c[2001][2001];
int main() {
    fastio;
    c[0][0] = c[1][0] = c[1][1] = 1;
    for(int i = 2; i <= 2000; i++) {
        for(int j = 0; j <= i; j++) {
            if(j == 0 || j == i) c[i][j] = 1;
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
            c[i][j] %= MOD;
        }
    }

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = c[n][k];
    ll tmp = 0;
    for(int i = 0; i <= k - 1; i++) {
        tmp += c[k-1][i];
        tmp %= MOD;
    }
    cout << (ans * tmp) % MOD << '\n';

    return 0;
}