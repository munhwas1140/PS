#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    int ans = 2;
    int now = 2;
    int tmp, prev;
    cin >> tmp;
    prev = tmp;
    for(int i = 1; i < n; i++) {
        cin >> tmp;
        if(tmp == prev && now != -1) {
            now *= 2;
        } else now = 2;

        ans += now;
        if(ans >= 100) {
            ans = 0;
            now = -1;
        } 
        prev = tmp;
    }    
    cout << ans << '\n';
      
    return 0;
}