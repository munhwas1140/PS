#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
ll extend_gcd(ll k, ll c) {
    vector<ll> S = {0, 1}, T = {1, 0}, R = {k, c};
    ll Q, r2, r1, tmp;
    while(1) {
        r2 = R[R.size() - 2];
        r1 = R[R.size() - 1];
        ll tmp = r2 % r1;
        R.push_back(r2 % r1);
        if(tmp == 0) {
            return S.back();
        }

        Q = r2 / r1;
        S.push_back(S[S.size() - 2] - Q * S[S.size() - 1]);
        T.push_back(T[T.size() - 2] - Q * T[T.size() - 1]);
    }

}
void solve() {
    ll k, c;
    cin >> k >> c;
    if(gcd(k, c) != 1) {
        cout << "IMPOSSIBLE" << '\n';
        return ;
    }

    ll ans = extend_gcd(k, c);
    while(c*ans <= k) ans += k;
    if(ans > 1e9) {
        cout << "IMPOSSIBLE" << '\n';
        return ;
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