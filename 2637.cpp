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
vector<pii> g[101];
int ind[101];
int outd[101];
int cnt[101];
int main() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        g[t1].push_back({t2, t3});
        ind[t2]++;
        outd[t1]++;
    }
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(ind[i] == 0) {
            cnt[i] = 1;
            q.push(i);
        }
    }     
    vector<int> ans;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        
        for(auto &next : g[now]) {
            ind[next.first]--;
            cnt[next.first] += next.second * cnt[now];
            if(ind[next.first] == 0) {
                if(outd[next.first] == 0) ans.push_back(next.first);
                q.push(next.first);
            }
        }
    }
    
    sort(ans.begin(), ans.end());
    for(int x : ans) {
        cout << x << ' ' << cnt[x] << '\n';
    }

    return 0;
}