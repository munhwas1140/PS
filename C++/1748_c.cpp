#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    vector<ll> p(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i == 0) p[i] = a[i];
        else p[i] = p[i - 1] + a[i];
    }

    int ans = 0;

    int it = 0 ;
    while(it < n && a[it] != 0) {
        if(p[it] == 0) ans++;
        it++;
    }

    if(it == n) {
        cout << ans << '\n';
        return ;
    }

    for(int i = it; i < n; i++) {
        if(a[i] == 0) {
            int mcnt = 1;
            map<ll,int> mp;
            mp[p[i]] = 1;
            i++;
            while(i < n) {
                if(a[i] == 0) {
                    i -= 1;
                    break;
                } else {
                    if(mp.count(p[i])) {
                        mp[p[i]]++;
                        if(mcnt < mp[p[i]]) {
                            mcnt = mp[p[i]];
                        }
                    } else {
                        mp[p[i]] = 1;
                    }
                }
                i++;
            }
            ans += mcnt;
        }
    }

    cout << ans << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}