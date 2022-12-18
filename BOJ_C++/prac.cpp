#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    string str; cin >> str;
    ll o, z;
    o = z = 0;
    for(int i = 0; i < n; i++) {
        if(str[i] == '1') {
            o++;
        } else {
            z++;
        }
    }
    ll s = 1;
    ll e = (1 << n);
    for(int i = 0; i < o; i++) {
        s += (1 << i);
    }
    for(int i = 0; i < z; i++) {
        e -= (1 << i);
    }
    for(ll i = s; i <= e; i++) {
        cout << i << ' ';
    }
}
int main() {
    fastio;
    solve();
    return 0;
}