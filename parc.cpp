#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1);
    a[1] = x;
    a[n] = 1;

    if(x == n) {
        cout << n << ' ';
        for(int i = 2; i < n; i++) {
            cout << i << ' ';
        }
        cout << 1 << '\n';
        return ;
    }

    if(n % x != 0) {
        cout << -1 << '\n';
        return ;
    } else {
        vector<int> tt;
        for(int i = 2; i < n; i++) {
            a[i] = i;
        }
        
        int tmp = n / x;
        int t2 = tmp;
        for(int i = 2; i <= tmp; i++) {
            while(t2 % i == 0) {
                tt.push_back(i);
                t2 /= i;
            }
        }
 
        int sz = tt.size();
        t2 = n;
        for(int i = sz - 1; i >= 0; i--) {
            a[t2 / tt[i]] = t2;
            t2 /= tt[i];
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
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