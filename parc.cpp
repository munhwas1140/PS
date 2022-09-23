#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        int n, k; cin >> n >> k;
        vector<ll> a(n + 2);
        for(int i = 1; i <= n; i++) cin >> a[i];
        int l = k;
        int r = k;
        ll now = a[k];
        while(true) {
            if(a[l - 1] > a[r + 1]) {
                now += a[l - 1];
                l -= 1;
            } else if(a[r + 1] > a[l - 1]) {
                now += a[r + 1];
                r += 1;
            } else {
                
            }
            if(l == 0 || r == n + 1 || now < 0) break;
        }
        
        if(l == 0 || r == n + 1) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
        
    }
 
    return 0;
}