#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    map<int,int> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        ++mp[a[i]];
    }
    
    if(mp.size() == 1) {
        for(int i = 0; i < n; i++) {
            cout << 0 << ' ';
        }
        cout << '\n';
    } else {
        auto it = mp.end();
        it--;
        int MAX = it->first;
        if(mp[MAX] > 1) {
            for(int i = 0; i < n; i++) {
                cout << a[i] - MAX << ' ';
            }
            cout << '\n';
        } else {
            it--;
            int SMAX = it->first;
            for(int i = 0; i < n; i++) {
                if(a[i] == MAX) {
                    cout << a[i] - SMAX << ' ';
                } else {
                    cout << a[i] - MAX << ' ';
                }
            }
            cout << '\n';
        }
    }
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}