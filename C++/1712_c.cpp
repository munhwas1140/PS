#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]] = i;
    }
    
    queue<int> pass;
    vector<bool> del(100001);
    int e = -1;
    int ans = 0;
    for(int i = 0; i < n - 1; i++) {
        if(i < e) {
            if(!del[a[i]]) {
                ans++;
                del[a[i]] = true;
                e = max(e, mp[a[i]]);
            }
            continue;
        }
        if(a[i] > a[i + 1] && !del[a[i]]) {
            ans++;
            e = max(e, mp[a[i]]);
            del[a[i]] = true;
            while(!pass.empty()) {
                int now = pass.front();
                pass.pop();
                if(!del[now]) {
                    ans++;
                    e = max(e, mp[now]);
                    del[now] = true;
                }
            }
            continue;
        }
        pass.push(a[i]);
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