#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

vector<int> g[1001];
int visited[1001];
void DFS(int now) {
    visited[now] = true;
    cout << now << ' ';
    for(int &next : g[now]) {
        if(!visited[next]) {
            DFS(next);
        }
    }
}
void BFS(int now) {
    visited[now] = true;
    queue<int> q;
    q.push(now);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        cout << now << ' ';
        for(int &next : g[now]) {
            if(!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}
int main() {
    fastio;
    int n, m, v;
    cin >> n >> m >> v;
    for(int i = 0; i < m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    for(int i = 1; i <= n; i++) {
        sort(g[i].begin(), g[i].end());
    }
      
    DFS(v);
    cout << '\n';
    memset(visited,false,sizeof(visited));
    BFS(v);
    return 0;
}