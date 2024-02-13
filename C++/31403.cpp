#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int a, b, c;
    cin >> a >> b >> c;
    cout << a + b - c << '\n';
    cout << stoi(to_string(a) + to_string(b)) - c << '\n';
    return 0;
}