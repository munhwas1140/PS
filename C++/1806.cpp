#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;

int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
      
    int l = 0, r = 0, sum = 0;
    int ans = 1e9;
    
    while(true) {
        if(sum < m) {
            if(r == n) break;
            sum += a[r++];
        } else if(sum >= m) {
            ans = min(ans, r - l); 
            sum -= a[l++];
        }
    }
    if(ans == 1e9) cout << 0 << '\n';
    else cout << ans << '\n';
    return 0;
}