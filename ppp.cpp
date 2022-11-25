#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    if(n == 2) {
        cout << 3 << ' ' << 1 << '\n';
        return ;
    }
    

    for(ll e = n + 2; e < n + 30; e++) {
        ll x = (e - 1) * (e - 1);
        ll b = (e * (e + 1)) / 2;
        ll a = ((e - n) * (e - n + 1)) / 2;
        
        cout << b - a<< ' ' << n * n << '\n';
        if(n + 3 + e <= x && x <= b - a + 1) {

        }
    }
    

}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}