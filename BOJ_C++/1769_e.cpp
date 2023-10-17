#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    bool flag = false;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
        if(!flag && b[i] == 0) {
            b[i] = 1;
            flag = true;
        }
    }

    ll ze = 0;
    ll tmp = 0;
    ll ans = 0;
    flag = false;
    for(int i = n - 1; i >= 0; i--) {
        if(a[i] == 0) ze++;
        else {
            ans += ze;
            if(!flag) {
                a[i] = 0;
                flag = true;
            }
        }
    }
    
    ze = 0;
    tmp = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(b[i] == 0) ze++;
        else tmp += ze;
    }
    ans = max(ans, tmp);

    ze = 0;
    tmp = 0;
    for(int i = n - 1; i >= 0; i--) { 
        if(a[i] == 0) ze++;
        else tmp += ze;
    }
    ans = max(ans, tmp);

    cout << ans << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}