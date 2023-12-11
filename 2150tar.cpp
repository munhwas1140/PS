#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m, cnt;
int low[10001], dfsn[10001];
bool visited[10001];
vector<int> g[10001];
stack<int> st;
vector<vector<int>> ans;

void dfs(int now) {
    visited[now] = true;
    st.push(now);
    dfsn[now] = ++cnt;
    low[now] = cnt;

    for(int next : g[now]) {
        if(!dfsn[next]) { // edge(u, v) => tree edge
            dfs(next);
            low[now] = min(low[now], low[next]);
        } else if(visited[next]) { // edge(u, v) => back edge
            low[now] = min(low[now], dfsn[next]);
        }
    }

    if(low[now] == dfsn[now]) {
        vector<int> scc;
        while(!st.empty()) {
            int poped = st.top();
            st.pop();
            scc.push_back(poped);
            visited[poped] = false;
            if(now == poped) break;
        }
        sort(scc.begin(), scc.end());
        ans.push_back(scc);
    }
}

int main() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
    }
    for(int i = 1; i <= n; i++) {
        if(!dfsn[i]) dfs(i);
    }
    sort(ans.begin(), ans.end());

    cout << (int)ans.size() << '\n';
    for(auto &scc : ans) {
        for(int x : scc) {
            cout << x << ' ';
        }
        cout << -1 << '\n';
    }

    return 0;
}