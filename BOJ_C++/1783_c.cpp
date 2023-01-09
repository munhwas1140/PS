#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    vector<int> b(n);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i - 1] = a[i];
    }
    sort(b.begin(), b.end());

    int s, e;
    s = e = 0;
    int sum = 0;
    int ans = n + 1;
    while(s < n && e < n && s <= e) {
        while(e < n && sum + b[e] <= m) {
            sum += b[e];
            e++;
        }
        int tmp = n - (e - s) + 1;
        if(e == 0) break;
        else if(e - s == n) {
            ans = 1; break;
        } else if(sum - b[e - 1] + a[e - s + 1] <= m) tmp--;
        ans = min(ans, tmp);
        sum -= b[s];
        s++;
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