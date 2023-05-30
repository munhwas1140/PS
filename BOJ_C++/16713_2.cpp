#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, q;
int a[1000001];
int p[1000001];
int main() {
    fastio;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        p[i] = p[i - 1] ^ a[i];
    }
    int ans = 0;
    while(q--) {
        int s, e;
        cin >> s >> e;
        ans ^= p[e] ^ p[s - 1];
    }
    cout << ans << '\n';

    return 0;
}