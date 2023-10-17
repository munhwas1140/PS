#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    vector<pll> a(n);
    ll l = 0, r = 0;
    for(auto &[x, y] : a) {
        cin >> x >> y;
        r += y;
    }

    sort(a.begin(), a.end());

    for(auto &[x, y] : a) {
        l += y;
        r -= y;
        if(l >= r) {
            cout << x << '\n';
            return 0;
        }
    }
    
    return 0;
}