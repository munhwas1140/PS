#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int,int> mp[n];
    function<int(int, int)> go = [&] (int idx, int c) {
        if(idx == n || c == 0) return 0;

        if(mp[idx].count(c)) return mp[idx][c];
        int &ret = mp[idx][c];
        
        if(c >= a[idx]) ret = go(idx + 1, c) + 1;
        else ret = max(go(idx + 1, c - 1) + 1, go(idx + 1, c));
        return ret;
    };
    
    go(0, q);
    function<void(int, int)> trace = [&] (int idx, int c) {
        if(idx == n || c == 0) {
            cout << string(n - idx, '0');
            return ;
        }
        int now = go(idx, c);
        if(c >= a[idx]) {
            cout << 1;
            trace(idx + 1, c);
        } else {
            if(go(idx + 1, c - 1) + 1 == now) {
                cout << 1;
                trace(idx + 1, c - 1);
            } else {
                cout << 0;
                trace(idx + 1, c);
            }
        }
    };
    trace(0, q);
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