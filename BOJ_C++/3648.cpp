#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
int n, m;
vector<int> g[2001], gp[2001], order;
bool visited[2001];
void dfs(int now) {
    visited[now] = true;
    for(int &next : g[now]) {
        if(!visited[next]) dfs(next);
    }
    order.push_back(now);
}
void dfs_rev(int now, int num) {

}
int main() {
    fastio;
    while(cin >> n >> m) {
        for(int i = 0; i < m; i++) {
            int t1, t2; cin >> t1 >> t2;

        }
    }

    return 0;
}