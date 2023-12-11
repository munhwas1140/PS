#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    string a, b;
    cin >> a >> b;
    int cnt = 0;
    vector<pii> ans;
    for(int i = 0; i < n; i++) {
        if(a[i] == '1') {
            cnt++;
            int it = i;
            while(it < n && a[it] == '1') it++; 
            ans.push_back({i + 1, it});
        }
    }
    
    if(cnt) {
        if(cnt % 2) {
            for(int i = 0; i < n; i++) {
                if(a[i] == '0') {
                    b[i] = '1' - b[i] + '0';
                }
            }
        } else {
            for(int i = 0; i < n; i++) {
                if(a[i] == '1') {
                    b[i] = '1' - b[i] + '0';
                }
            }
        }
    }

    string tmp(n, '0');
    if(tmp == b) {
        cout << ans.size() << '\n';
        for(auto p : ans) {
            cout << p.first << ' ' << p.second << '\n';
        }
        return ;
    } 
        
    string tmp2(n, '1');
    if(tmp2 == b) {
        cout << ans.size() + 3 << '\n';
        cout << 1 << ' ' << n << '\n';
        cout << 1 << ' ' << 1 << '\n';
        cout << 2 << ' ' << n << '\n';
        for(auto p : ans) {
            cout << p.first << ' ' << p.second << '\n';
        }
        return ;
    }
    cout << "NO" << '\n';
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