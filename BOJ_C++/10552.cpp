#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
int a[100001];
bool visited[100001];
int n, m, p;
int DFS(int now) {
    visited[now] = true;
    int ret = 1;
    if(!a[now]) return 0;
    int next = a[now];
    if(visited[next]) {
        return 1e9;
} else ret += DFS(next); 
    return ret;
}
int main() {
    fastio;
    cin >> n >> m >> p; 
    for(int i = 0; i < n; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        if(a[t2] == 0) a[t2] = t1;
    }

    int ans = DFS(p); 
    if(ans >= 1e9) cout << -1 << '\n';
    else cout << ans << '\n';

    return 0;
}