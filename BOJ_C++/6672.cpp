#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m, cnt;
int dfsn[10000], low[10000], bcccnt[10000];
stack<pii> st;
vector<vector<pii>> BCC;
vector<int> g[10000];

void dfs(int now, int par = -1) {
    dfsn[now] = ++cnt;
    low[now] = cnt;
    
    for(int next : g[now]) {
        if(next == par) continue;
        st.push({now, next});

        if(!dfsn[next]) {
            dfs(next, now);
            low[now] = min(low[now], low[next]);
            if(low[next] >= dfsn[now]) {
                BCC.emplace_back();
                while(!st.empty()) {
                    auto p = st.top();
                    st.pop();
                    BCC.back().push_back(p);
                    if(p == pii(now, next)) break;
                }
            }
        } else {
            low[now] = min(low[now], dfsn[next]);
        }
    }
}

void init() {
    cnt = 0;
    memset(dfsn, 0, sizeof(dfsn));
    memset(low, 0, sizeof(low));
    memset(bcccnt, 0, sizeof(bcccnt));
    BCC.clear();
    while(!st.empty()) st.pop();
    for(int i = 0; i < 10000; i++) g[i].clear();
}
int main() {
    fastio;
    while(true) {
        init();
        cin >> n >> m;
        if(!n && !m) break;

        for(int i = 0; i < m; i++) {
            int t1, t2;
            cin >> t1 >> t2;
            g[t1].push_back(t2);
            g[t2].push_back(t1);
        }

        for(int i = 0; i < n; i++) {
            if(!dfsn[i]) dfs(i);
        }

        cout << BCC.size() << '\n';
    }

    return 0;
}