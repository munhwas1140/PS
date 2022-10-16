#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int f(int n) {
    if(n == 0) return 1;
    return n * f(n - 1);
}
int main() {
    fastio;
    int n; cin >> n;
    cout << f(n) << '\n';
    return 0;
}