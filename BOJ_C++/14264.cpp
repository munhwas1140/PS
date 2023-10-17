#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    double n; cin >> n;
    cout << fixed << setprecision(10);
    cout << n * n * sin(60 * M_PI / 180) / 2.0<< '\n';

    return 0;
}