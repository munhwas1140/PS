#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int dist[1000001];
int main() {
    fastio;
    int f,s,g,u,d;
    cin >> f >> s >> g >> u >> d;
    memset(dist,-1,sizeof(dist));

    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        
        if(now + u <= f && dist[now + u] == -1) {
            dist[now + u] = dist[now] + 1;
            q.push(now + u);
        } 
        if(now - d >= 1 && dist[now - d] == -1) {
            dist[now - d] = dist[now] + 1;
            q.push(now - d);
        }
    }
    if(dist[g] == -1) {
        cout << "use the stairs" << '\n';
    } else cout << dist[g] << '\n';
      
    return 0;
}