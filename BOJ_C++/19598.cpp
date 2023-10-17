#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    vector<pii> p;
    for(int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        p.push_back({s, 1});
        p.push_back({e, -1});
    }

    sort(p.begin(), p.end());
    
    int ans = -1;
    int now = 0;
    for(auto &[d, x] : p) {
        if(x == 1) now++;
        if(x == -1) now--;
        ans = max(ans, now);
    }

    cout << ans << '\n';
    return 0;
}