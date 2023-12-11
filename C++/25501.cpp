#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int cnt;
int go(string &str, int l, int r) {
    cnt++;
    if(l >= r) return 1;
    else if(str[l] != str[r]) return 0;
    return go(str, l + 1, r - 1);
}
void solve() {
    string str;
    cin >> str;
    
    cnt = 0;
    cout << go(str, 0, str.size() - 1) << ' ';
    cout << cnt << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}