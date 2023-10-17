#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
vector<int> v[21];
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    int allgcd = -1;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(i == 1) allgcd = a[i];
        else {
            allgcd = gcd(allgcd, a[i]);
        }
    }

    if(allgcd == 1) {
        cout << 0 << '\n';
        return ;
    }

    int ans = 1e9;
    for(int i = n; i >= 1; i--) {
        int tmp = 0;
        int now = allgcd;
        for(int x : v[i]) {
            now = gcd(now, x);
            tmp += n - x + 1;
            if(now == 1) break;
        }
        ans = min(ans, tmp);
    }

    cout << ans << '\n';


    return ;
}
int main() {
    fastio;
    for(int i = 1; i <= 20; i++) {
        int now = i;
        v[i].push_back(i);
        for(int j = i; j >= 1; j--) {
            bool ok = true;
            for(int k : v[i]) {
                if(gcd(k, j) != 1) {
                    ok = false;
                }
            }
            if(ok) v[i].push_back(j);
        }
    }
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}