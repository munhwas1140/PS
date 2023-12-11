#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
vector<int> g[100001];
vector<int> gp[100001];
vector<int> order;
bool visited[100001];
int SCC[100001];
int sz[100001];
int n, m;
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
    sz[num]++;
    for(int &next : gp[now]) {
        if(!visited[next]) dfs_rev(next, num);
    }
}
void init() {
    for(int i = 0; i < 100001; i++) {
        g[i].clear();
        gp[i].clear();
    }
    order.clear();
    memset(visited,false,sizeof(visited));
    memset(sz,0,sizeof(sz));
    memset(SCC,0,sizeof(SCC));
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        init();
        cin >> n >> m;
        for(int i = 0; i < m; i++) {
            int t1, t2;
            cin >> t1 >> t2;
            g[t1].push_back(t2);
            gp[t2].push_back(t1);
        }
        
        for(int i = 0; i < n; i++) {
            if(!visited[i]) dfs(i);
        }
        
        memset(visited,false,sizeof(visited));
        reverse(order.begin(), order.end());
        
        int cnt = 0;
        for(int &i : order) {
            if(!SCC[i]) dfs_rev(i, ++cnt);
        }
        int idx = -1;
        for(int i = 1; i <= cnt; i++) {
            if(sz[i] > 1) {
                if(idx == -1) {
                    idx = i;
                } else {
                    idx = -100;
                }
            }
        }
        if(idx == -100 || idx == -1) {
            cout << "Confused" << '\n';
        } else {
            bool ok = true;
            for(int i = 0; i < n; i++) {
                for(int &next : g[i]) {
                    int t1 = SCC[i];
                    int t2 = SCC[next];
                    if(t1 != t2 && t2 == idx) {
                        ok = false;
                        break;
                    }
                }
            }
            if(ok) {
                for(int i = 0; i < n; i++) {
                    if(SCC[i] == idx) {
                        cout << i << '\n';
                    }
                }
            } else {
                cout << "Confused" << '\n';
            }
        }
        cout << '\n';
    }

    return 0;
}