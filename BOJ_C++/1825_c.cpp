#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a;
    int l, r;
    l = r = 0;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        if(tmp == -1) l++;
        else if(tmp == -2) r++;
        else a.push_back(tmp);
    }

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    
    int ans = 0;
    ans = max(ans, l + (int)a.size());
    ans = max(ans, r + (int)a.size());
    ans = min(ans, m);

    for(int i = 0; i < a.size(); i++) {
        int t1 = min(a[i] - 1, i + l);
        int t2 = min(m - a[i], (int)(a.size() - i - 1 + r));
        ans = max(ans, t1 + t2 + 1);
    }
    cout << ans << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}