#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    int o, z;
    o = z = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 1) {
            o++;
        } else { 
            z++;
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