#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
map<int, int> mp;
bool isDom(int x, int y) {
    map<int,int>::iterator it = mp.lower_bound(x);
    if(it == mp.end()) return false;
    return y < it->second;
}
void remove(int x, int y) {
    map<int,int>::iterator it = mp.lower_bound(x);
    if(it == mp.begin()) return ;
    it--;

    while(true) {
        if(it->second > y) break;
        if(it == mp.begin()) {
            mp.erase(it);
            break;
        } else {
            map<int,int>::iterator tt = it;
            tt--;
            mp.erase(it);
            it = tt;
        }
    }
    return ;
}
int go(int x, int y) {
    if(isDom(x, y)) return (int)mp.size();
    remove(x, y);
    mp[x] = y;
    return (int)mp.size();
}
void solve() {
    mp.clear();
    int n; cin >> n;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ans += (ll)go(x, y);
    }
    cout << ans << '\n';
    return ;
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }    
    return 0;
}