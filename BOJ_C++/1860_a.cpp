#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    string str; cin >> str;
    int n = str.size();
    
    if(str == "()") cout << "NO" << '\n';
    else {
        cout << "YES" << '\n';
        string t1 = "", t2 = "";
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                t1 += '(';
                t2 += ')';
            }
            else {
                t1 += ')';
                t2 += '(';
            }
        }

        if(str == t1 || str == t2) {
            cout << string(n, '(') + string(n, ')') << '\n';
        } else {
            for(int i = 0; i < 2 * n; i++) {
                if(i % 2 == 0) cout << '(';
                else cout << ')';
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