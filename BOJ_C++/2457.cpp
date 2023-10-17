#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int main() {
    fastio;
    int n; cin >> n;
    vector<pair<pii, pii>> a(n);
    for(auto &[s, e] : a) {
        cin >> s.first >> s.second >> e.first >> e.second;
    }

    sort(a.begin(), a.end());

    int cnt = 0;
    pii st = {3,1};

    for(int i = 0; i < n; i++) {
        if(st > make_pair(11, 30)) break;
        int it = i;
        pii mx = {-1, -1};
        while(it < n && a[it].first <= st) {
            mx = max(mx, a[it].second);
            it++;
        }
        cnt++;
        st = mx;
        if(it == i) break;
        i = it - 1;
    }

    if(st > make_pair(11, 30)) cout << cnt << '\n';
    else cout << 0 << '\n';
    return 0;
}