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
vector<string> a;
vector<int> g[301];
vector<int> gp[301];
vector<tuple<int,int,int>> gs[301];
vector<int> order;
vector<int> SCC_v[301];
int indeg[301];
int SCC[301];
bool visited[301];

void init() {
    memset(SCC,0,sizeof(SCC));
    a.clear();
    order.clear();
    memset(visited,false,sizeof(visited));
    memset(indeg,0,sizeof(indeg));
    for(int i = 1; i <= 300; i++) {
        gs[i].clear();
        g[i].clear();
        gp[i].clear();
        SCC_v[i].clear();
    }
}
void dfs(int now) {
    visited[now] = true;
    for(int &next : g[now]) {
        if(!visited[next]) dfs(next);
    }
    order.push_back(now);
}
void dfs_rev(int now, int num) {
    visited[now] = true;
    SCC[now] = num;
    for(int &next : gp[now]) {
        if(!visited[next]) dfs_rev(next, num);
    }
    SCC_v[num].push_back(now);
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        init();
        cin >> n;
        a.resize(n + 1);
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i] = " " + a[i];
        }

        for(int k = 1; k <= n; k++) {
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= n; j++) {
                    if(i == j || i == k || k == j) continue;
                    if(a[i][k] == '1' && a[k][j] == '1' && a[i][j] == '1') {
                        a[i][j] = '0';
                    }
                }
            }
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i == j) continue;
                if(a[i][j] == '1') {
                    g[i].push_back(j);
                    gp[j].push_back(i);
                }
            }
        }

        for(int i = 1; i <= n; i++) {
            if(!visited[i]) dfs(i);
        }

        reverse(order.begin(), order.end());
        memset(visited,false,sizeof(visited));

        int Scnt = 0;
        for(int &i : order) {
            if(!SCC[i]) dfs_rev(i, ++Scnt);
        }
 
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i == j || a[i][j] == '0') continue;
                int x = SCC[i];
                int y = SCC[j];
                if(x != y) {
                    gs[x].push_back({y, i, j});
                    indeg[y]++;
                }
            }
        }
    
        vector<pair<int,int>> pos;
        queue<int> q;
        for(int i = 1; i <= Scnt; i++) {
            if(indeg[i] == 0) q.push(i);
        }
        
        while(!q.empty()) {
            int now = q.front();
            q.pop();
            
            for(auto &[next, s, e] : gs[now]) {
                indeg[next]--;
                pos.push_back({s, e});
                if(indeg[next] == 0) {
                    q.push(next);
                }
            }
        }

        int ans = pos.size();

        for(int i = 1; i <= Scnt; i++) {
            if(SCC_v[i].size() == 1) continue;
            ans += SCC_v[i].size();
        }
        cout << ans << '\n';
        for(auto &p : pos) {
            cout << p.first << ' ' << p.second << '\n';
        } 
        for(int i = 1; i <= Scnt; i++) {
            if(SCC_v[i].size() == 1) continue;
            for(int j = 0; j < SCC_v[i].size() - 1; j++) {
                cout << SCC_v[i][j] << ' ' << SCC_v[i][j + 1] << '\n';
            }
            cout << SCC_v[i][SCC_v[i].size() - 1] << ' ' << SCC_v[i][0] << '\n';
        }
        cout << '\n';
    }
    return 0;
}