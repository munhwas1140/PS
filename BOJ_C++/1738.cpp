#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
vector<pair<int, ll>> g[101];
ll dist[101];
int pre[101];
bool visited[101];
void go(int now) {
    if(now == -1) return ;
    go(pre[now]);
    cout << now << ' ';
}
bool check(int now) {
    if(now == -1) return false;
    visited[now] = true;
    if(pre[now] != -1 && visited[pre[now]]) return true;
    return check(pre[now]);
}
int main() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int t1, t2;
        ll t3;
        cin >> t1 >> t2 >> t3;
        g[t1].push_back({t2, t3});
    }
    for(int i = 1; i <= n; i++) {
        dist[i] = -1e14;
        pre[i] = -1;
    }
    dist[1] = 0;
    set<int> s;
    for(int i = 0; i < n + 1; i++) {
        for(int j = 1; j <= n; j++) {
            if(dist[j] == -1e14) continue;
            for(auto &p : g[j]) {
                if(dist[p.first] < dist[j] + p.second) {
                    if(i == n - 1) {
                        dist[p.first] = 1e14;
                        dist[j] = 1e14;
                        pre[p.first] = j;
                    }  else {
                        pre[p.first] = j;
                        dist[p.first] = dist[j] + p.second;
                    }
                }
            }
        }
    }

    if(check(n) || dist[n] == -1e14) cout << -1 << '\n';
    else go(n);
    return 0;
}