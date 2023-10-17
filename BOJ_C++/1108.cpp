#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;

map<string, int> ID;
vector<int> g[2525];
vector<int> gp[2525];
vector<int> order;
vector<int> gs[2525];
vector<vector<int>> SCCS;
int SCC[2525];
int SCCindeg[2525];
bool visited[2525];
int IDcnt, SCCcnt;
ll dist[2525];
void dfs(int now) {
    visited[now] = true;
    for(int &next : g[now]) {
        if(!visited[next]) dfs(next);
    }
    order.push_back(now);
}
vector<int> curSCC;
void dfs_rev(int now, int num) {
    visited[now] = true;
    SCC[now] = num;
    for(int &next : gp[now]) {
        if(!visited[next]) dfs_rev(next, num);
    }
    curSCC.push_back(now);
}
int main() {
    fastio;
    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        string e; cin >> e;
        if(!ID.count(e)) ID[e] = ++IDcnt;
        int k; cin >> k;
        for(int j = 0; j < k; j++) {
            string s; cin >> s;
            if(!ID.count(s)) ID[s] = ++IDcnt;
            g[ID[s]].push_back(ID[e]);
            gp[ID[e]].push_back(ID[s]);
        }
    }

    for(int i = 1; i <= IDcnt; i++) {
        if(!visited[i]) dfs(i);
        dist[i] = 1LL;
    }

    memset(visited,false,sizeof(visited));
    reverse(order.begin(), order.end());

    SCCS.push_back(vector<int>());
    for(int &i : order) {
        curSCC.clear();
        if(!SCC[i]) {
            dfs_rev(i, ++SCCcnt);
            SCCS.push_back(curSCC);
        }
    }

    for(int i = 1; i <= IDcnt; i++) {
        for(int &next : g[i]) {
            int s = SCC[i];
            int e = SCC[next];
            if(s != e) {
                SCCindeg[e]++;
                gs[s].push_back(e);
            }
        }
    }

    queue<int> q;
    for(int i = 1; i <= SCCcnt; i++) {
        if(SCCindeg[i] == 0) q.push(i);
    } 
    order.clear();
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        order.push_back(now);
        for(int &next : gs[now]) {
            SCCindeg[next]--;
            if(SCCindeg[next] == 0) {
                q.push(next);
            }
        }
    }
    
    for(int &seq : order) {
        for(int now : SCCS[seq]) {
            for(int &next : g[now]) {
                int s = SCC[now];
                int e = SCC[next];
                if(s != e) {
                    dist[next] += dist[now];
                }
            }
        }
    }

    string target;
    cin >> target;
    cout << dist[ID[target]] << '\n';
    return 0;
}