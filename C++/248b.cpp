#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;

int main() {
    fastio;
    ll a, b, k;
    cin >> a >> b >> k;
    int cnt = 0;
    while(a < b) {
        cnt++;
        a *= k;
    }
    cout << cnt << '\n';
    return 0;
}