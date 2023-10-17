#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int n, nodeidx;
int cnt[10001];
pair<int,int> g[10001];
int low[10001];
int high[10001];
void DFS(int now, int dep) {
    if(g[now].first != -1) DFS(g[now].first, dep + 1);
    low[dep] = min(low[dep], nodeidx);
    high[dep] = max(high[dep], nodeidx++);
    if(g[now].second != -1) DFS(g[now].second, dep + 1);
}
int main() {
    fastio;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        low[i] = 1e9;
    }
    for(int i = 0; i < n; i++) {
        int p, c1, c2;
        cin >> p >> c1 >> c2;

        g[p].first = c1;
        g[p].second = c2;
        if(c1 != -1) cnt[c1] += 1;
        if(c2 != -1) cnt[c2] += 1;
    }
      
    int root;
    for(int i = 1; i <= n; i++) {
        if(!cnt[i]) root = i;
    }

    nodeidx = 1;
    DFS(root, 1);
    int ret = high[1] - low[1] + 1;
    int level = 1;
    for(int i = 2; i <= n; i++) {
        if(ret < high[i] - low[i] + 1) {
            ret = high[i] - low[i] + 1;
            level = i;
        }
    }
    cout << level << ' ' << ret << '\n';
    return 0;
}