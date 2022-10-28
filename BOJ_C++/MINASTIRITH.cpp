#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
vector<pair<double, double>> range;
const double pi = 2 * acos(0);
int solveLinear(double begin, double end) {
    int idx = 0, ret = 0;
    while(begin < end) {
        double Max = -1;
        while(idx < n && range[idx].first <= begin) {
            Max = max(Max, range[idx].second);
            idx++;
        }

        if(Max <= begin) {
            return 1e9;
        }

        begin = Max;
        ret++;
    }
    return ret;
}
int solveCircular() {
    int ret = 1e9;
    for(int i = 0; i < n; i++) {
        if(range[i].first <= 0 || range[i].second >= 2 * pi) {
            double begin = fmod(range[i].second, 2 * pi);
            double end = fmod(range[i].first + 2 * pi, 2 * pi);
            ret = min(ret, 1 + solveLinear(begin, end));
        }
    }
    return ret;
}
void solve() {
    cin >> n;
    vector<pair<double, double>> a(n);
    vector<double> r(n);
    
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second >> r[i];
    }

    range.clear();
    range.resize(n);
    for(int i = 0; i < n; i++) {
        double pos = fmod(2 * pi + atan2(a[i].second, a[i].first), 2 * pi);
        double pm = 2.0 * asin(r[i] / 16.0);
        range[i] = make_pair(pos - pm, pos + pm);
    }

    sort(range.begin(), range.end());
    int ans = solveCircular();
    if(ans == 1e9) {
        cout << "IMPOSSIBLE" << '\n';
    } else {
        cout << ans << '\n';
    }
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}