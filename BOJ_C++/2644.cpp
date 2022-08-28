#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

vector<int> g[101];
int dist[101];
int main() {
    fastio;
    int n;
    cin >> n;
    int t1, t2;
    cin >> t1 >> t2;

    int m;
    cin >> m;
    while(m--) {
        int i, j;
        cin >> i >> j;
        g[i].push_back(j);
        g[j].push_back(i);
    }
    memset(dist,-1,sizeof(dist));
    dist[t1] = 0;
    queue<int> q;
    q.push(t1);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(int next : g[now]) {
            if(dist[next] == -1) {
                dist[next] = dist[now] + 1;
                q.push(next);
            }
        }
    } 
    cout << dist[t2] << '\n';
      
    return 0;
}