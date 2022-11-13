#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int check[10];
void solve() {
    int n; cin >> n;
    string str; cin >> str;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        memset(check,0,sizeof(check));

        for(int j = 0; j < min(100, i + 1); j++) {
            check[str[i - j] - '0']++;
        
            int tmp = 0;
            int mv = -1;
            for(int k = 0; k < 10; k++) {
                if(check[k]) tmp++;
                mv = max(mv, check[k]);
            }

            if(tmp >= mv) ans++;
        }
    }
    cout << ans << '\n';
    
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}