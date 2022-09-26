#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;

vector<double> a, b;
int n;
double f(double m) {
    double ret = -1e9;
    for(int i = 0; i < n; i++) {
        ret = max(ret, b[i] + abs(m - a[i]));
    }
    return ret;
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        a.clear();
        b.clear();
        cin >> n;
        double l = 1e9, r = -1e9;
        a.resize(n); b.resize(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            l = min(l, a[i]);
            r = max(r, a[i]);
        }
        for(int j = 0; j < n; j++) {
            cin >> b[j];
        }

        double s = l;
        double e = r;
        while(e - s >= 0.0000001) {
            double p = (s * 2 + e) / 3.0;
            double q = (s + e * 2) / 3.0;
            if(f(p) <= f(q)) e = q;
            else s = p;
        }
        cout << fixed << setprecision(6);
        cout << s << '\n';
    }
    return 0;
}