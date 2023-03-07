#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
// 1 2 3 4 5 6 7 8 9 0
// 2 5 5 4 5 6 3 7 6 6
int a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
void solve() {
    int n; cin >> n;


    
    if(n % 2) {
        cout << 7;
        n -= 3;
    }
    for(int i = 0; i < n / 2; i++) {
        cout << 1;
    }
    cout << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
} 