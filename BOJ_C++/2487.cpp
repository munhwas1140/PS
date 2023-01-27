#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<bool> visited(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    function<int(int)> go = [&] (int now) {
        visited[now] = true;
        int ret = 1;
        if(visited[a[now]]) return 1;
        ret += go(a[now]);
        return ret;
    };

    vector<int> cycle;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            cycle.push_back(go(i));
        }
    }

    int ans = -1;
    for(int &x : cycle) {
        if(ans == -1) ans = x;
        else ans = lcm(ans, x);
    }
    cout << ans << '\n';


    return 0;
}