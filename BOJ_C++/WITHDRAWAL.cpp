#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int c[1000], r[1000];
int n, k;
bool check(double mid) {

    vector<double> v(n);
    for(int i = 0; i < n; i++) {
        v[i] = mid * c[i] - r[i];
    }

    sort(v.begin(), v.end());
    double sum = 0;
    for(int i = n - k; i < n; i++) {
        sum += v[i];
    }

    return sum >= 0;
}
void solve() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> r[i] >> c[i];
    }
    double l = 0, r = 1.0;
    double ans;
    for(int i = 0; i < 100; i++) {
        double mid = (l + r) / 2.0;
        if(check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << fixed << setprecision(10);
    cout << l << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}