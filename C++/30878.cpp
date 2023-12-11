#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int m; cin >> m;
    stack<pll> st;
    
    ll x1, x2, y1, y2;
    x1 = (60 - m) * m * m * 3;
    y1 = 60 * 60 * 60;

    x2 = m * m * m * 3;
    y2 = 60 * 3 * 3600;

    ll ax, ay;
    ax = x1 * y2 + x2 * y1;
    ay = y1 * y2;
    ll gc = gcd(ax, ay);
    ax /= gc;
    ay /= gc;
    cout << ax << '/' << ay << '\n';
    
    return 0;
}