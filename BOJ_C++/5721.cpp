#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
void solve() {
    cin >> n >> m;
    if(n == 0 && m == 0) return ;
    vector<vector<int>> a(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }


    
}
int main() {
    fastio;
    while(true) {
        solve();
    }
    return 0;
}