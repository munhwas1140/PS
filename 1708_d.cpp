#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = n - 1; i >= 1; i--) {
        int pre = a[i + 1], ok = false;
        for(int j = i; j >= 1; j--) {
            ok = (a[j] == 0);
            pre -= (a[j] = pre - a[j]);
            if(ok) {
                sort(a.begin() + j, a.begin() + i + 1);
                break;
            }
        }
        if(!ok) {
            sort(a.begin() + 1, a.begin() + i + 1);
        }
    }
    cout << a[1] << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}