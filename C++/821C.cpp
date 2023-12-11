#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
int n;
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        cin >> n;
        vector<int> a(n + 1);
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        cout << n - 1 << '\n';
        if(n > 1) cout << 1 << ' ' << n << '\n';
        int x = ((a[1] + a[n]) % 2) ? a[1] : a[n]; 
        for(int i = 2; i < n; i++) {
            if((x + a[i]) % 2) {
                cout << 1 << ' ' << i << '\n';
            } else {
                cout << i << ' ' << n << '\n';
            }
        }
    }

    return 0;
}