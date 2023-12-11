#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
double dist(pair<double, double> &u, pair<double, double> &v) {
    double ret = (u.first - v.first) * (u.first - v.first);
    ret += (u.second - v.second) * (u.second - v.second);
    return ret;
}
int main() {
    fastio;
    int n; cin >> n;
    vector<pair<double, double>> a(n);

    for(auto &[x, y] : a) {
        cin >> x >> y;
    }

    cout << fixed << setprecision(10);
    if(n == 1) {
        cout << a[0].first << ' ' << a[1].second << '\n';
        return 0;
    }
    
    pair<double, double> t1 = a[0];
    pair<double, double> t2 = a[1];

    double mx = dist(a[0], a[1]);

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            double now = dist(a[i], a[j]);
            if(now > mx) {
                mx = now;
                t1 = a[i];
                t2 = a[j];
            }
        }
    }
    cout << t1.first << ' ' << t1.second << '\n';
    cout << t2.first << ' ' << t2.second << '\n';
    cout << (t1.first + t2.first) / 2.0 << ' ' << (t1.second + t2.second) / 2.0 << '\n';

    return 0;
}