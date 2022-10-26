#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    int tmp;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(i == 1) tmp = a[i];
        else {
            tmp = gcd(tmp, a[i]);
        }
    }

    if(tmp == 1) {
        cout << 0 << '\n';
        return ;
    }
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    
    return 0;
}