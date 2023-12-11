#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n;
    ll m;
    cin >> n >> m;
    vector<pii> pos;
    for(int i = 0; i < n; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        if(t1 > t2) {
            pos.push_back({t2, t1});
        }
    }

    int sz = pos.size();
    sort(pos.begin(), pos.end());
    int s, e;
    s = e = -1;    
    ll ans = 0;
    for(auto &[l, r] : pos) {
        if(e < l) {
            ans += e - s;
            s = l;
            e = r;
        } else {
            e = max(e, r);
        }
    }
    ans += e - s;
    ans = ans * 2 + m;
    cout << ans << '\n';

    return 0;
}