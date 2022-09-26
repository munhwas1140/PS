#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
const ll con = 998244353;
int main() {
    fastio;
    ll n; cin >> n;
    cout << ((n % con) + con) % con << '\n';
    
    return 0;
}