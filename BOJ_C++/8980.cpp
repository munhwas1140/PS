#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
struct asdf { 
    int s, e, x;
};
int main() {
    fastio;
    int n, c;
    cin >> n >> c;
    int m; cin >> m;
    vector<asdf> a(m);
    for(auto &[s, e, x] : a) {
        cin >> s >> e >> x;
    }

    sort(a.begin(), a.end(), [](asdf &u, asdf &v) {
        if(u.e == v.e) {
            return u.s > v.s;
        }
        return u.e < v.e;
    });

    vector<int> tv(n + 1);
    int ans = 0;
    for(auto &[s, e, x] : a) {
        int t1 = 1e9;
        for(int i = s; i < e; i++) {
            t1 = min(t1, c - tv[i]);
        }
        int tmp = min(x, t1);
        ans += tmp;
        for(int i = s; i < e; i++) {
            tv[i] += tmp;
        }
    }

    cout << ans << '\n';
    
    return 0;
}