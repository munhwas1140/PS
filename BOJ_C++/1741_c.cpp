#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int a[2001];
int psum[2001];
void solve() {
    memset(a,0,sizeof(a));
    memset(psum,0,sizeof(psum));
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i];
    }
    int ans = 1e9;
    for(int i = 1; i <= n; i++) {
        int thick = i;
        int cnt = 0;
        int nowsum = 0;
        int sum = psum[i];
        bool ok = true;
        for(int j = i + 1; j <= n; j++) {
            cnt++;
            nowsum += a[j];
            if(nowsum == sum) {
                thick = max(thick, cnt);
                nowsum = 0;
                cnt = 0;
            } else if(nowsum > sum) {
                ok = false;
                break;
            }
        }
        if(ok && nowsum == 0) {
            ans = min(ans, thick);
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