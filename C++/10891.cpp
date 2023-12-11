#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m, cnt;
int dfsn[100001], low[100001];
int poscnt[100001];
vector<int> g[100001];
vector<vector<pii>> BCC;
stack<pii> st;
void dfs(int now, int p = -1) {
    dfsn[now] = ++cnt;
    low[now] = cnt;

    for(int next : g[now]) {
        if(next == p) continue;

        if(dfsn[now] > dfsn[next]) st.push({now, next});
        if(dfsn[next]) low[now] = min(low[now], dfsn[next]);
        else {
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
            
        }
    }
}
int main() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    
    for(int i = 1; i <= n; i++) {
        if(!dfsn[i]) dfs(i);
    }

    int sz = BCC.size();
    for(int i = 0; i < sz; i++) {
        if(BCC[i].size() == 1) continue;
        set<int> S;
        for(auto &[x, y] : BCC[i]) {
            S.insert(x); S.insert(y);
        }

        if(BCC[i].size() != S.size()) {
            return !(cout << "Not cactus" << '\n');
        }

        for(auto it = S.begin(); it != S.end(); it++) {
            poscnt[*it]++;
            if(poscnt[*it] > 1) {
                return !(cout << "Not cactus" << '\n');
            }
        }
    }
    cout << "Cactus" << '\n';

    return 0;
}