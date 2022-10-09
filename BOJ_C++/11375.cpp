#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
vector<int> g[1001];
int l[1001], r[1001];
bool visited[1001];
bool dfs(int now) {
    visited[now] = true;
    for(int next : g[now]) {
        if(r[next] == -1 || !visited[r[next]] && dfs(r[next])) {
            r[next] = now;
            l[now] = next;
            return true;
        }
    }
    return false;
}
int main() {
    fastio;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int k; cin >> k;
        for(int j = 0; j < k; j++) {
            int next; cin >> next;
            g[i].push_back(next);
        }
    }
    int match = 0;
    memset(l,-1,sizeof(l));
    memset(r,-1,sizeof(r));
    for(int i = 1; i <= n; i++) {
        if(l[i] == -1) {
            memset(visited,false,sizeof(visited));
            if(dfs(i)) match++;
        }
    }
    cout << match << '\n';

    return 0;
}