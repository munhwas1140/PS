#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
vector<int> g[201];
int a[201], b[201];
bool visited[201];
bool dfs(int now) {
    visited[now] = true;
    for(int next : g[now]) {
        if(b[next] == -1 || !visited[b[next]] && dfs(b[next])) {
            a[now] = next;
            b[next] = now;
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
    memset(a,-1,sizeof(a));
    memset(b,-1,sizeof(b));
    for(int i = 1; i <= n; i++) {
        if(a[i] == -1) {
            memset(visited,false,sizeof(visited));
            if(dfs(i)) match++;
        }
    }
    cout << match << '\n';

    return 0;
}