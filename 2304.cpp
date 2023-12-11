#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int a[1001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        a[t1] = t2;
    }
    int l = 0, r = 1000;
    int lmax = a[l], rmax = a[r];
    int ans = 0;
    while(l <= r) {
        if(lmax >= rmax) {
            ans += rmax;
            r -= 1;
            rmax = max(rmax, a[r]);
        } else {
            ans += lmax;
            l += 1;
            lmax = max(lmax, a[l]);
        }
        // cout << lmax << ' ' << rmax << ' ' << ans << '\n';
    } 
    cout << ans << '\n'; 
      
    return 0;
}