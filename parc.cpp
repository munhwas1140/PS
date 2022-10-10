#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}
int main() {
    fastio;
    int tc;
    cin >> tc;
    while(tc--) {
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        bool ok = true;
        for(int i = 0; i < n - 2; i++) {
            if(gcd(a[i], a[i + 2]) > gcd(a[i], a[i + 1])) {
                ok = false;
                break;
            }
        }


        
        if(ok) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    return 0;
}