#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, k;
void solve() {
    cin >> n >> k;
    vector<pii> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i].second;
    }
    
    sort(a.begin(), a.end());
    int np = k;

    int it = 0;
    while(true) {
        while(it < n && a[it].first <= np) {
            it++;
        }
        if(it == n) {
            cout << "YES" << '\n';
            return ;
        }
        int minv = 1e9 + 1;
        for(int i = it; i < n; i++) {
            minv = min(minv, a[i].second);
        }
        k -= minv;
        np += k;
        if(k <= 0) {
            cout << "NO" << '\n';
            return ;
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