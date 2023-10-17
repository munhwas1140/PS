#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int UNWATCHED = 0;
const int WATCHED = 1;
const int INSTALLED = 2;

int ans = 0;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<bool> visited(n);
    for(int i = 0; i < m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    
    function<int(int)> go = [&] (int now) {
        visited[now] = true;
        int child[3] = {0, 0, 0};
        for(int &next : g[now]) {
            if(!visited[next]) {
                ++child[go(next)];
            }
        }

        if(child[UNWATCHED]) {
            ++ans;
            return INSTALLED;
        }

        if(child[INSTALLED]) {
            return WATCHED;
        }
        return UNWATCHED;
    };

    ans = 0;
    for(int i = 0; i < n; i++) {
        if(!visited[i] && go(i) == UNWATCHED) {
            ans++;
        }
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