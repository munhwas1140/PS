#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;


int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    ll ans = 0, tmp = 1;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i > 0) {
            if(a[i] != a[i-1]) tmp += i + 1;
            else tmp += 1;
        } 
        ans += tmp;
    }
    // cout << ans << '\n';
    while(m--) {
        int idx, v;
        cin >> idx >> v;
        idx -= 1;


        if(idx > 0) {
            if(a[idx-1] == a[idx] && a[idx - 1] != v) {
                ans += (n - idx) * idx;
            } else if(a[idx - 1] != a[idx] && a[idx - 1] == v) {
                ans -= (n - idx) * idx;
            }
        }
        if(idx < n - 1) {
            if(a[idx + 1] != a[idx] && a[idx + 1] == v) {
                ans -= (n - (idx + 1)) * (idx + 1);
            } else if(a[idx + 1] == a[idx] && a[idx + 1] != v) {
                ans += (n - (idx + 1)) * (idx + 1);
            }
        }
        a[idx] = v;
        cout << ans << '\n';
    }
      
    return 0;
}