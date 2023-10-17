#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
bool friends[10][10];
bool check[10];
int n, m;
int go() {
    int first = -1;
    for(int i = 0; i < n; i++) {
        if(!check[i]) {
            first = i;
            break;
        }
    }

    if(first == -1) return 1;
    int ret = 0;
    for(int i = first + 1; i < n; i++) {
        if(!check[i] && friends[first][i]) {
            check[first] = check[i] = true;
            ret += go();
            check[first] = check[i] = false;
        }
    }
    return ret;
}
void solve() {
    memset(friends,false,sizeof(friends));
    memset(check,false,sizeof(check));
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        friends[t1][t2] = true;
        friends[t2][t1] = true;
    }
    cout << go() << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }

    return 0;
}