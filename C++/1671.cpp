#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
vector<tuple<int,int,int>> a;
vector<int> g[100];
int l[100], r[50];
bool visited[100];
bool dfs(int now) {
    visited[now] = true;
    for(int next : g[now]) {
        if(r[next] == -1 || !visited[r[next]] && dfs(r[next])) {
            r[next] = now;
            l[now] = next;
            return true;
        }
    }
    return false;
}
int main() {
    fastio;
    cin >> n;
    a.resize(n);
    for(auto &[x,y,z] : a) cin >> x >> y >> z;
    
    sort(a.rbegin(), a.rend());
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            auto [x1, y1, z1] = a[i];
            auto [x2, y2, z2] = a[j];
            if(x1 >= x2 && y1 >= y2 && z1 >= z2) {
                g[2 * i].push_back(j);
                g[2 * i + 1].push_back(j);
            }
        }
    }
    int ans = 0;
    memset(l,-1,sizeof(l));
    memset(r,-1,sizeof(r));

    for(int i = 0; i < 2 * n; i++) {
        if(l[i] == -1) {
            memset(visited,false,sizeof(visited));
            if(dfs(i)) ans++;
        }
    }
    cout << n - ans << '\n';
    
    return 0;
}