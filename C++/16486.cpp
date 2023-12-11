#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    double PI = 3.141592;
    double d1, d2;
    cin >> d1 >> d2;
    cout << fixed << setprecision(6);
    cout << d1 * 2 + PI * d2 * 2 << '\n';
    return 0;
}