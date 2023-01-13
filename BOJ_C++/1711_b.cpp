#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<vector<int>> g(n);
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    } 

    while(m--) {
        int t1, t2;
        cin >> t1 >> t2;
        t1--; t2--;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
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