#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n, l;
    cin >> n >> l;

    vector<double> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    double ans = 1e18;

    for(int i = 0; i < n; i++) {
        double sum = 0;
        for(int j = i; j < n; j++) {
            int size = j - i + 1;
            sum += a[j];
            if(size >= l) {
                double tmp  = sum / (size);
                ans = min(ans, tmp);
            }
        }
    }

    cout << fixed << setprecision(10);
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