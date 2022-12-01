#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m, k;
int main() {
    fastio;
    cin >> n >> m;
    vector<string> a(n);
    map<string, int> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        ++mp[a[i]];
    }
    cin >> k;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int cnt = 0;
        for(int j = 0; j < m; j++) {
            if(a[i][j] == '0') cnt++;
        }

        if(cnt > k || (cnt % 2) != (k % 2)) continue;
        ans = max(ans,mp[a[i]]);
    }
    cout << ans << '\n';
    return 0;
}