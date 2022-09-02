#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int n;
vector<pair<int,int>> g[10001];
bool visited[10001];
int maxidx;
int maxdist = -1;
int nowdist = 0;
void go(int now) {
    if(nowdist > maxdist) {
        maxdist = nowdist;
        maxidx = now;
    }
    visited[now] = true; 
    for(auto &[next, dist] : g[now]) {
        if(!visited[next]) {
            nowdist += dist;
            go(next);         
            nowdist -= dist;
        }
    }
}
void DFS(int now, int d) {
    maxdist = max(maxdist, d);
    visited[now] = true; 
    for(auto &[next, dist] : g[now]) {
        if(!visited[next]) {
            DFS(next, d + dist);
        }
    }
}
int main() {
    fastio;
    cin >> n;

    for(int i = 0; i < n - 1; i++) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        g[t1].push_back({t2,t3});
        g[t2].push_back({t1,t3});
    }

    go(1);
    maxdist = 0;
    memset(visited,false,sizeof(visited));
    DFS(maxidx, 0);
    cout << maxdist << '\n';
    return 0;
}