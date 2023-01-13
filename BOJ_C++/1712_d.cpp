#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int s = 0, e = (int)1e9;
    int ans;
    while(s <= e) {
        int mid = (s + e) / 2;
        vector<int> b = a;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(b[i] * 2 < mid) {
                b[i] = 1e9;
                cnt++;
            }
        }

        bool two = false, one = false;
        for(int i = 0; i < n; i++) {
            if(b[i] >= mid) {
                one = true;
            }
            if(i < n - 1 && min(b[i], b[i + 1]) >= mid) {
                two = true;
            }
        }

        cnt += !two + !one;
        if(cnt <= k) {
            ans = mid;
            s = mid + 1;
        } else e = mid - 1;
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