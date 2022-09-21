#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
int fibo(int n) {
    if(n <= 1) return n;
    return fibo(n - 1) + fibo(n - 2);
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        cout << fibo(n) << '\n';
    }
    return 0;
}