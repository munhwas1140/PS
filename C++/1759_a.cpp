#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    string str;
    cin >> str;
    string tmp = "Yes";
    auto it = 0;
    
    while(it < 3 && tmp[it] != str[0]) it++;
    if(it == 3) {
        cout << "NO" << '\n';
        return ;
    }

    int n = str.size();
    for(int i = 0; i < n; i++) {
        if(str[i] != tmp[it]) {
            cout << "NO" << '\n';
            return ;
        }
        it++;
        if(it == 3) it = 0;
    }

    cout << "YES" << '\n';
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