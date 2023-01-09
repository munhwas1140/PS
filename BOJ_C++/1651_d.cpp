#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
map<int,vector<pii>> mp[200002];
set<int> check[200002];
set<int> st[200002];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
vector<pii> go(int x, int y) {
    if(x < 1 || y < 1 || x > 200000 || y > 200000) {
        return vector<pii>(1, {x, y});
    }
    check[x].insert(y);
    if(!st[x].count(y)) return vector<pii>(1, {x, y});
    if(mp[x].count(y)) return mp[x][y];

    vector<vector<pii>> poss;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(check[nx].count(ny)) continue;
        poss.push_back(go(nx,ny));
    }

    int tmp = 1e9;
    for(auto pos : poss) {
        for(auto [nx, ny] : pos) {
            ll t = abs(x - nx) + abs(y - ny);
            if(t < tmp) {
                tmp = t;
            }
        }
    }

    vector<pii> tv;
    for(auto pos : poss) {
        for(auto [nx, ny] : pos) {
            ll t = abs(x - nx) + abs(y - ny);
            if(t == tmp) {
                tv.push_back({nx, ny});
            }
        }
    }
    mp[x][y] = tv;
    return tv;
}
int main() {
    fastio;
    int n; cin >> n;
    vector<pii> a(n);
    for(auto &[x, y] : a) {
        cin >> x >> y;
        st[x].insert(y);
    }

    for(int i = 0; i < n; i++) {
        auto ans = go(a[i].first, a[i].second);
        cout << ans[0].first << ' ' << ans[0].second << '\n';
    }
    return 0;
}