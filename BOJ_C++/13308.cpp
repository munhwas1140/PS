// #include <bits/stdc++.h>
// using namespace std;

// 주유소

// long long cost[2501];
// vector<pair<int, long long>> g[2501];
// long long dist[2501][2501];
// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);
//     int n, m;
//     cin >> n >> m;
//     for(int i = 1; i <= n; i++) {
//         cin >> cost[i];
//     }

//     while(m--) {
//         int a, b;
//         long long c;
//         cin >> a >> b >> c;
//         g[a].push_back({b,c});
//         g[b].push_back({a,c});
//     }

//     for(int i = 1; i <= n; i++) {
//         for(int j = 1; j <= n; j++) {
//             dist[i][j] = LLONG_MAX;
//         }
//         dist[i][i] = 0;
//         long long c = cost[i];
//         priority_queue<pair<long long,int>> pq;
//         pq.push({0,i});
//         while(!pq.empty()) {
//             auto [d, now] = pq.top();
//             pq.pop();
//             d = -d;
//             if(dist[i][now] < d) continue;
//             for(auto &next : g[now]) {
//                 if(dist[i][next.first] > d + next.second * c) {
//                     dist[i][next.first] = d + next.second * c;
//                     pq.push({-dist[i][next.first], next.first});
//                 }
//             }
//         } 
//     }

//     long long ans[2501];
//     for(int i = 1; i <= n; i++) {
//         ans[i] = LLONG_MAX;
//     }
//     ans[1] = 0;
//     priority_queue<pair<long long,int>> pq;
//     pq.push({0,1});
//     while(!pq.empty()) {
//         auto [d, now] = pq.top();
//         pq.pop(); 
        
//         d = -d;
//         if(ans[now] < d) continue;
//         for(int i = 1; i <= n; i++) {
//             if(i == now) continue;
//             if(ans[i] > d + dist[now][i]) {
//                 ans[i] = d + dist[now][i];
//                 pq.push({-ans[i], i});
//             }
//         }
//     }
//     cout << ans[n] << '\n';
//     return 0;
// }


// #include <bits/stdc++.h>
// using namespace std;
// long long cost[2501];
// vector<pair<int,long long>> g[2501];
// long long dist[2501][2501];
// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);
//     int n, m;
//     cin >> n >> m;
//     for(int i = 1; i <= n; i++) {
//         cin >> cost[i];
//     }
//     while(m--) {
//         int a, b;
//         long long c;
//         cin >> a >> b >> c;
//         g[a].push_back({b,c});
//         g[b].push_back({a,c});
//     }
    
//     for(int i = 0; i <= 2500; i++) {
//         for(int j = 0; j <= 2500; j++) {
//             dist[i][j] = LLONG_MAX;
//         }
//     }

//     dist[cost[1]][1] = 0;
//     priority_queue<tuple<long long,long long,int>> pq;
//     pq.push({0,cost[1], 1});

//     while(!pq.empty()) {
//         auto [d,mincost, now] = pq.top();
//         pq.pop();
//         d = -d;
//         if(dist[mincost][now] < d) continue;
//         for(auto next : g[now]) {
//             if(dist[mincost][next.first] > d + mincost * next.second) {
//                 dist[mincost][next.first] = d + mincost * next.second;
//                 pq.push({-(d + mincost * next.second), min(mincost, cost[next.first]), next.first});
//             }
//         }
//     }

//     long long ans = LLONG_MAX;
//     for(int i = 1; i <= 2500; i++) {
//         ans = min(ans, dist[i][n]);
//     }

//     cout << ans << '\n';
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct asdf {
    ll node, cost, dst;
    asdf(int a, int b, long long c) : node(a), cost(b), dst(c) {}
    bool operator <(asdf r) const { return dst > r.dst;}
};

ll n,m,node[3000];
vector<pair<int,int>> g[3000];
bool chk[3000][3000];

long long dijkstra() {
    priority_queue<asdf> pq;
    pq.push(asdf(1,node[1],0));
    while(!pq.empty()) {
        asdf now = pq.top();
        ll idx = now.node, cost = now.cost, dist = now.dst;
        pq.pop();

        if(chk[idx][cost]) continue;
        if(idx == n) return dist;

        chk[idx][cost] = 1;
        for(auto next : g[idx]) {
            pq.push(asdf(next.first, min(cost, node[next.first]), cost * next.second + dist));
        }
    
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> node[i];
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    
    cout << dijkstra();
    return 0;
}