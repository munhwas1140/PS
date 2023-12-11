#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n, k;
    cin >> n >> k;
    vector<double> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    double s1 = 0, s2 = 0;
    for(int i = k; i < n - k; i++) {
        s1 += a[i];
        s2 += a[i];
        if(i == k || i == n - k - 1) {
            s2 += a[i] * k;
            if(k == n - k - 1) {
                s2 += a[i] * k;
            }
        }
    }


    cout << fixed;
    cout << setprecision(2);
    cout << (s1 + 1e-10) / (n - 2 * k) << '\n';
    cout << (s2 + 1e-10) / (n) << '\n';
    return 0;
}