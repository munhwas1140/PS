#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
ll Binomial(int n, int r) {
    if(r < 0 || r > n) return 0;
    ll ret = 1;
    for(int i = 0; i < r; i++) ret *= n - i;
    for(int i = 0; i < r; i++) ret /= r - i;
    return ret;
}
string go(int n, int k) {
    if(k == 1) return "1" + string(n - 1, '0');
    ll cnt = 0;
    for(int i = k; ; i++) {
        ll res = Binomial(i, k) - Binomial(i - 1, k);
        if(cnt + res >= n) {
            string s = go(n - cnt, k - 1);
            return "1" + string(i - 1 - s.size(), '0') + s;
        }
        cnt += res;
    }
}
int main() {
    fastio;
    int n, k;
    cin >> n >> k;
    cout << go(n, k) << '\n';
    return 0;
}