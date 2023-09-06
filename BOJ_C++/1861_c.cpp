#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    string str; cin >> str;
    int sz = 0;
    int maxSortedPref = 0;
    int minNotSortedPref = 0;
    bool ok = true;
    
    for(char c : str) {
        if(c == '+') {
            sz++;
        } else if(c == '-') {
            sz--;
            maxSortedPref = min(maxSortedPref, sz);
            if(sz < minNotSortedPref) {
                minNotSortedPref = 0;
            }
        } else if(c == '1') {
            maxSortedPref = max(maxSortedPref, sz);
        } else {
            if(sz <= 1) {
                ok = false;
                break;
            }
            if(minNotSortedPref == 0 || minNotSortedPref > sz) {
                minNotSortedPref = sz;
            }
        }
        if(minNotSortedPref <= maxSortedPref && minNotSortedPref != 0) {
            ok = false;
            break;
        }
    }
    if(ok) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}