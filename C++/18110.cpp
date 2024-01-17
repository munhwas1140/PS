#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    if(n == 0) {
        cout << 0 << '\n';
    } else {
        int x = (int) round(double(n) * 0.15);
        vector<double> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        double sum = 0;
        for (int i = x; i < n - x; i++) {
            sum += a[i];
        }
        cout <<  round(sum / (n - 2 * x)) << '\n';
    }
    return 0;
}