#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    string str; cin >> str;
    int n = str.size();    

    for(int i = 0; i < n; i++) {
        int it = i;
        while(it + 1 < n && str[it] == str[it + 1]) it++;
        if(it - i < 1) {
            cout << "NO" << '\n';
            return ;
        }
        i = it;
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