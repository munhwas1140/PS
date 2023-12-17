#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
ll extend_gcd(ll n, ll a) {
    vector<ll> S = {1, 0}, T = {0, 1}, R = {n, a};
    ll Q;
    ll r1, r2, tmp;
    while(1) {
        r2 = R[R.size() - 2];
        r1 = R[R.size() - 1];

        tmp = r2 % r1;
        R.push_back(tmp);
        if(tmp == 0) return T.back();
        Q = r2 / r1;
        S.push_back(S[S.size() - 2] - S[S.size() - 1] * Q);
        T.push_back(T[T.size() - 2] - T[T.size() - 1] * Q);
    }
}
int main() {
    fastio;
    ll n, a;
    cin >> n >> a;
    cout << n - a << ' ';
    if(gcd(n, a) != 1) {
        cout << -1 << '\n';
        return 0;
    }
    ll ans = extend_gcd(n, a);
    while(ans < 0) {
        ans += n;
    }
    cout << ans << '\n';
    return 0;
}