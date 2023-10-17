#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    string str;
    cin >> str;
    int q, a;
    q = a = 0;
    for(int i = 0; i < n; i++) {
        if(str[i] == 'Q') q++;
        else a++;
    }
    if(q > a + 1 || a == 0 && q > 0) cout << "No" << '\n';
    else cout << "Yes" << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}