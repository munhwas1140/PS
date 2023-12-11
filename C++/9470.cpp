#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
int ind[1001];
vector<int> g[1001];
int dist[1001];
bool check[1001];
int k, m, p;
int main() {
    fastio;
    int tc;
    cin >> tc;
    while(tc--) {
        memset(ind,0,sizeof(ind));
        memset(dist,0,sizeof(dist));
        memset(check,false,sizeof(check));
        for(int i = 1; i <= 1000; i++) {
            g[i].clear();
        }
        cin >> k >> m >> p;
        for(int i = 0; i < p; i++) {
            int t1, t2;
            cin >> t1 >> t2;
            g[t1].push_back(t2);
            ind[t2]++;
        }
        queue<int> q;
        for(int i = 1; i <= m; i++) {
            if(!ind[i]) {
                dist[i] = 1;
                q.push(i);
            }
        }     

        while(!q.empty()) {
            int now = q.front();
            q.pop();
            
            for(int next : g[now]) {
                
                if(dist[next] < dist[now]) {
                    dist[next] = dist[now];
                    check[next] = true;
                } else if(check[next] && dist[next] == dist[now]) {
                    dist[next] = dist[now] + 1;
                    check[next] = false;
                }
                    
                ind[next]--;
                if(ind[next] == 0) q.push(next);
            }
        }

        cout << k << ' ' << dist[m] << '\n';
    }

    return 0;
}