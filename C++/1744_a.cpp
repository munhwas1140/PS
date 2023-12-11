#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int itoc[51];
    memset(itoc,-1,sizeof(itoc));
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    string str; cin >> str;
    for(int i = 0; i < n; i++) {
        if(itoc[a[i]] == -1) {
            itoc[a[i]] = str[i];
        } else {
            if(itoc[a[i]] != str[i]) {
                cout << "NO" << '\n';
                return ;
            }
        }
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