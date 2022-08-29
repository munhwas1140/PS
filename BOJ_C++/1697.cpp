#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int dist[100001];
int main() {
    fastio;
    memset(dist,-1,sizeof(dist));
    int n, k;
    cin >> n >> k; 
      
    queue<int> q;
    q.push(n);
    dist[n] = 0;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        if(now == k) break;

        if(now - 1 >= 0) {
            if(dist[now-1] == -1) {
                dist[now-1] = dist[now] + 1;
                q.push(now-1);
            }
        }    
        if(now + 1 <= 100000) {
            if(dist[now+1] == -1) {
                dist[now+1] = dist[now] + 1;
                q.push(now +1);
            }
        }
        if(now * 2 <= 100000){
            if(dist[now * 2] == -1) {
                dist[now * 2] = dist[now] + 1;
                q.push(now * 2);
            }
        }
    }
    cout << dist[k] << '\n';
    return 0;
}