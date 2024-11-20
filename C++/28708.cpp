#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m, a[8];
vector<tuple<int,int,int>> g;
map<vector<int>, int> mp;

int go(vector<int> now) {
    bool f = true;
    for(int i = 0; i < n - 1; i++) {
        if(a[now[i]] > a[now[i + 1]]) {
            f = false;
            break;
        }
    }
    if(f) return 0;


    if(mp.count(now) != 0) return mp[now];
    mp[now] = 1e9;

    vector<int> next = now;
    for(int i = 0; i < m; i++) {
        auto [s, e, t] = g[i];
        swap(next[s], next[e]);
        mp[now] = min(mp[now], go(next) + t);
        swap(next[s], next[e]);
    }

    return mp[now];
}
int main() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        int s, e, t;
        cin >> s >> e >> t;
        g.emplace_back(s - 1, e - 1, t);
    }

    vector<int> st;
    for(int i = 0; i < n; i++) {
        st.push_back(i);
    }

    cout << go(st) << '\n';

    return 0;
}
