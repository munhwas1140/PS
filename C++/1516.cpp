#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;

int n;
vector<int> g[501];
int ind[501];
int t[501];
int dist[501];
int main() {
    fastio;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> t[i];
        while(true) {
            int tmp; cin >> tmp;
            if(tmp == -1) break;
            g[tmp].push_back(i);
            ind[i] += 1;
        }
    }

    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(!ind[i]) q.push(i);
    }
    
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        dist[now] += t[now];
        for(int &next : g[now]) {
            ind[next]--;
            dist[next] = max(dist[next], dist[now]);
            if(ind[next] == 0) q.push(next);
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << dist[i] << '\n';
    }

    return 0;
}