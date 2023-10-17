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
    if(m == 0) return !(cout << 0 << '\n');

    sort(a.begin(), a.end());
    int l = 0, r = 0, ans = 2e9 + 1;
    int diff = 0;
    while(true) {
        if(diff < m) {
            if(r == n - 1) break;
            diff = a[++r] - a[l];
        } else if(diff >= m) {
            ans = min(ans, diff);
            diff = a[r] - a[++l]; 
        }
    }
      
    cout << ans << '\n';
    return 0;
}