#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<bool> check(m);
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    for(int i = 0; i < n; i++) {
        int t1 = a[i];
        int t2 = m - 1 - a[i];
        if(t1 > t2) swap(t1, t2);
        
        if(check[t1]) check[t2] = true;
        else check[t1] = true;
    }

    for(int i = 0; i < m; i++) {
        if(check[i]) cout << 'A';
        else cout << 'B';
    }
    cout << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}