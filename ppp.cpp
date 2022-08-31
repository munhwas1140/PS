#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;


int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i > 0) {
            if(a[i] != a[i-1]) ans += (n - (i + 1)) * (i + 1);
        }
    }
    
    while(m--) {
        int i, x; cin >> i >> x;
        i -= 1;

        ans -= (a[i] != a[i-1]) * (n - i) * i;
        ans -= (a[i] != a[i+1]) * (n - (i + 1)) * (i + 1);
        a[i] = x;
        ans += (a[i] != a[i-1]) * (n - i) * i;
        ans += (a[i] != a[i+1]) * (n - (n + 1)) * (i + 1);
        cout << ans + n * (n + 1) / 2 << '\n';
    }
    return 0;
}