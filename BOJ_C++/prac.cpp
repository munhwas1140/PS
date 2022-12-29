#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
pair<int,vector<int>> get(ull x) {
    int ret = 0;
    vector<int> pos;
    while(x) {
        pos.push_back(int(x % 10));
        ret++;
        x /= 10;
    }
    sort(pos.begin(), pos.end());
    pos.erase(unique(pos.begin(), pos.end()), pos.end());
    return make_pair(ret, pos);
}
set<ull> st;
void solve() {
    st.clear();
    int n;
    ull x;
    cin >> n >> x;

    if(get(x).first > n) {
        cout << -1 << '\n';
        return ;
    }

    queue<pair<ull, int>> q;
    q.push({x, 0});

    while(!q.empty()) {
        auto [now, cnt] = q.front();
        q.pop();

        if(st.count(now)) continue;
        st.insert(now);
        
        auto [sz, pos] = get(now);
        if(sz == n) {
            cout << cnt << '\n';
            return ;
        }

        for(int i = pos.size() - 1; i >= 0; i--) {
            q.push({now * ull(pos[i]), cnt + 1});
        }
    }
    cout << -1 << '\n';
}
int main() {
    fastio;
    solve();
    return 0;
}