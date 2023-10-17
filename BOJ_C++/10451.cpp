#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<bool> visited(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    function<void(int)> go = [&] (int now) {
        visited[now] = true;
        if(visited[a[now]]) return ;
        go(a[now]);
    };

    int cnt = 0; 
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            cnt++;
            go(i);
        }
    }
    cout << cnt << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}