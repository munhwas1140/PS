#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
bool check[1000];
void solve() {
    memset(check,false,sizeof(check));
    int m, s;
    cin >> m >> s;
    vector<int> a(m);
    bool ok = true;
    int maxv = -1;
    for(int i = 0; i < m; i++) {
        int tmp; cin >> tmp;
        maxv = max(tmp, maxv);
        if(check[tmp]) {
            ok = false;
        }
        check[tmp] = true;
    }

    if(!ok) {
        cout << "NO" << '\n';
        return;
    }

    int sum = 0;
    for(int i = 1; ; i++) {
        if(sum >= s) break;
        if(!check[i]) sum += i;
        check[i] = true;
    }
    
    if(sum > s) {
        cout << "NO" << '\n';
        return ;
    }

    for(int i = 1; i <= maxv; i++) {
        if(!check[i]) {
            cout << "NO" << '\n';
            return ;
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