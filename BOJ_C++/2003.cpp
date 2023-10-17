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
    for(int &x : a) cin >> x;
    int l = 0, r = 0;
    int ans = 0, sum = 0;

    while(true) {
        if(sum >= m) sum -= a[l++];
        else if(r == n) break;
        else sum += a[r++];
        if(sum == m) ans++;
    }
    cout << ans << '\n';
      
    return 0;
}