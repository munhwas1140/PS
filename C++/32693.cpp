#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
string a[500];
int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }   

    ll ans = 0;
    for(int i = 0; i < m - 1; i++) {
        for(int k = 1; ; k++) {
            if(i + 1 - k < 0 || i + k >= m ) break;
            ll now = 0;
            for(int j = 0; j < n; j++) {
                bool f = true;
                for(int x = 0; x < k; x++) {
                    if(a[j][i - x] != a[j][i + 1 + x]){
                        f = false;
                        break;
                    }
                }
                if(f) now += 1LL;
                else {
                    ans += now * (now + 1) / 2LL;
                    now = 0LL;
                }
            }
            ans += now * (now + 1) / 2LL;
        }
    }
    cout << ans << '\n';
    return 0;
}