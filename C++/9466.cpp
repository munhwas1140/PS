#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
int g[100001];
bool finished[100001];
bool visited[100001];
int cnt = 0;
void dfs(int now) {
    visited[now] = true;
    int next = g[now];
    if(!visited[next]) {
        dfs(next);
    } else {
        if(!finished[next]) {
            cnt++;
            for(int i = next; i != now; i = g[i]) {
                cnt++;
            }
        }
    }
    finished[now] = true;
}
void init() {
    memset(g,0,sizeof(g));
    memset(finished,false,sizeof(finished));
    memset(visited,false,sizeof(visited));
}
void solve() {
    init();
    cin >> n;
    cnt = 0;
    for(int i = 1; i <= n; i++) {
        cin >> g[i];
    }
    
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }
    cout << n - cnt << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}