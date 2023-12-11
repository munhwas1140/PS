#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;

vector<int> g[501];
int ind[501];
bool check[501][501];
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        memset(ind,0,sizeof(ind));
        memset(check,false,sizeof(check));
        for(int i = 0; i < 501; i++) {
            g[i].clear();
        }
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int t; cin >> t;
        while(t--) {
            int t1, t2;
            cin >> t1 >> t2;
            check[t1][t2] = true;
            check[t2][t1] = true;
        }

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int t1 = a[i];
                int t2 = a[j];
                if(!check[a[j]][a[i]]) {
                    g[t1].push_back(t2);
                    ind[t2]++;
                } else {
                    g[t2].push_back(t1);
                    ind[t1]++;
                }
            }
        }
        
        queue<int> q;
        for(int i = 1; i <= n; i++) {
            if(!ind[i]) q.push(i);
        }

        bool ambi = false;
        int cnt = 0;
        vector<int> ans;
        while(!q.empty()) {
            if(q.size() > 1) ambi = true;
            cnt++;
            int now = q.front();
            ans.push_back(now);
            q.pop();
            for(int next : g[now]) {
                ind[next]--;
                if(ind[next] == 0) q.push(next);
            } 
        }
        if(cnt != n) cout << "IMPOSSIBLE";
        else if(ambi) cout << "?";
        else for(int i : ans) cout << i << ' ';
        cout << '\n';
    }

    return 0;
}