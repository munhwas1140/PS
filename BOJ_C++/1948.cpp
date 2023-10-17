#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
int n, m, s, e;
int ind[10001];
int dist[10001];
bool visited[10001];
vector<pii> g[10001];
vector<int> p[10001];
int go(int now) {
    if(now == s) return 0;
    visited[now] = true;
    int ret = 0;
    for(int &next : p[now]) {
        if(!visited[next]) ret += go(next);
        ret += 1;
    }
    return ret;
} 
int main() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        g[t1].push_back({t2, t3});
        ind[t2]++;
    }
    cin >> s >> e;    
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(auto &next : g[now]) {
            ind[next.first]--;
            if(dist[next.first] < dist[now] + next.second) {
                dist[next.first] = dist[now] + next.second;
                p[next.first].clear();
                p[next.first].push_back(now);
            } else if(dist[next.first] == dist[now] + next.second) {
                p[next.first].push_back(now);
            }
            if(ind[next.first] == 0) q.push(next.first);
        }
    }

    cout << dist[e] << '\n';
    cout << go(e) << '\n';

    return 0;
}