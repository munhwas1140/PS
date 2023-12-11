#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int n, t, g;
int dist[100000];
int tran(int now) {
    if(now * 2 >= 99999) return 1e9;
    int tmp = 1;
    while(now * 2 >= tmp * 10) tmp *= 10;
    return now * 2 - tmp;
}
int main() {
    fastio;
    cin >> n >> t >> g;
    memset(dist,-1,sizeof(dist));
    dist[n] = 0;
    queue<int> q;
    q.push(n);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        if(dist[now] >= t) continue;
        if(now == g) break;
        if(now + 1 <= 99999 && dist[now + 1] == -1) {
            dist[now + 1] = dist[now] + 1;
            q.push(now + 1);
        }

        if(now == 0) continue;
        int next = tran(now); 
        if(next <= 99999 && dist[next] == -1) {
            dist[next] = dist[now] + 1;
            q.push(next);
        } 
    }


    if(dist[g] == -1) cout << "ANG" << '\n';
    else cout << dist[g] << '\n';
      
    return 0;
}