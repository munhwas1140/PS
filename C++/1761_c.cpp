#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
vector<int> g[101];
int ind[101];
bool ans[101][101];
void init() {
    for(int i = 0; i < 101; i++) {
        g[i].clear();
        ind[i] = 0;
        memset(ans[i],false,sizeof(ans[i]));
    }
}
void solve() {
    init();
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        str = " " + str;
        for(int j = 1; j <= n; j++) {
            if(str[j] == '1') {
                g[i].push_back(j);
                ind[j]++;
            }
        }
    }

    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(ind[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int now = q.front();
        ans[now][now] = true;
        q.pop();
        for(int &next : g[now]) {
            ind[next]--;
            for(int i = 1; i <= n; i++) {
                if(ans[now][i]) {
                    ans[next][i] = true;
                }
            }
            if(ind[next] == 0) {
                q.push(next);
            }
        }
    }

    
    for(int i = 1; i <= n; i++) {
        int cnt = 0;
        for(int j = 1; j <= n; j++) {
            if(ans[i][j]) cnt++;
        }

        cout << cnt << ' ';
        for(int j = 1; j <= n; j++) {
            if(ans[i][j]) cout << j << ' ';
        }
        cout << '\n';
    }
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}