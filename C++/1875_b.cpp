#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(n);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}