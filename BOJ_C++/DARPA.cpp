#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
bool check(int num, vector<double> &a, double gap) {
    
    double last = -1;
    int cnt = 0;
    for(int i = 0; i < a.size(); i++) {
        if(last <= a[i]) {
            cnt++;
            last = a[i] + gap;
        }
    }
    return cnt >= num;
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<double> a(m);
    for(int i = 0; i < m; i++) {
        cin >> a[i];
    }

    double l = 0, r = 240;
    double ans;
    for(int i = 0; i < 100; i++) {
        double mid = (l + r) / 2.0;
        if(check(n,a,mid)) {
            ans = mid;
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << fixed << setprecision(2);
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