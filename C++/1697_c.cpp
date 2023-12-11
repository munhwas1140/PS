#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    string s, t;
    int n; cin >> n;

    cin >> s >> t;
    if(s == t) {
        cout << "YES" << '\n';
        return ;
    }

    int it = -1;
    for(int i = 0; i < n; i++) {
        if(s[i] != t[i]) {
            if(t[i] == 'a') {
                cout << "NO" << '\n';
                return ;
            } else if(t[i] == 'b') {
                if(it == -1 || it < i) {
                    it = i;
                }
                while(it < n && s[it] == 'a') it++;
                if(it == n || s[it] != 'b') {
                    cout << "NO" << '\n';
                    return ;
                } else {
                    swap(s[i], s[it]);
                }
            } else {
                if(it == -1 || it < i) {
                    it = i;
                }
                while(it < n && s[it] == 'b') it++;
                if(it == n || s[it] != 'c') {
                    cout << "NO" << '\n';
                    return ;
                } else {
                    swap(s[i], s[it]);
                }
            }
        }
    }
    cout << "YES" << '\n';
    

}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}