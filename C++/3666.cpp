#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
vector<int> a;
int n;
int c[222][222], f[222][222];
vector<int> g[222];
vector<int> pos;
void init() {
    memset(c,0,sizeof(c));
    memset(f,0,sizeof(f));
    for(int i = 0; i < 222; i++) {
        g[i].clear();
    }
    a.clear();
    a.resize(n + 1);
    pos.clear();
}
bool flow(int mid) {
    for(int &p : pos) {
        c[n + p][2 * n + 1] = mid;
    }
    memset(f,0,sizeof(f));
    int total = 0;
    while(true) {
        vector<int> pre(2 * n + 2, -1);
        queue<int> q;
        q.push(0);
        while(!q.empty() && pre[2 * n + 1] == -1) {
            int now = q.front();
            q.pop();
            
            for(int next : g[now]) {
                if(pre[next] == -1 && c[now][next] - f[now][next] > 0) {
                    pre[next] = now;
                    q.push(next);
                    if(next == 2 * n + 1) break;
                }
            }
        }

        if(pre[2 * n + 1] == -1) break;

        int fl = 1e9;
        for(int i = 2 * n + 1; i != 0; i = pre[i]) {
            fl = min(fl, c[pre[i]][i] - f[pre[i]][i]);
        }

        for(int i = 2 * n + 1; i != 0; i = pre[i]) {
            f[pre[i]][i] += fl;
            f[i][pre[i]] -= fl;
        }
        total += fl;
    }

    // cout << mid << ' ' << total << '\n';
    for(int &p : pos) {
        if(c[n + p][2 * n + 1] != f[n + p][2 * n + 1]) return false;
    }
    return true;
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        cin >> n;
        init();
        
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            if(a[i]) {
                g[0].push_back(i);
                c[0][i] = a[i];
                
                g[i].push_back(0);
                c[i][0] = 0;
                
                g[i].push_back(n + i);
                c[i][n + i] = 1e9;

                g[n + i].push_back(i);
                c[n + i][i] = 0;
            }
        }

        for(int i = 1; i <= n; i++) {
            string str;
            cin >> str;
            str = " " + str;
            if(!a[i]) continue;
            bool tmp = true;
            for(int j = 1; j <= n; j++) {
                if(str[j] == 'Y') {
                    if(a[j] == 0) {
                        tmp = false;
                        continue;
                    }
                    c[i][n + j] = 1e9;
                    g[i].push_back(n + j);
                    c[n + j][i] = 0;
                    g[n + j].push_back(i);
                }
            }
            g[n + i].push_back(2 * n + 1);
            g[2 * n + 1].push_back(n + i);
            if(tmp) {
                c[n + i][2 * n + 1] = 1;
            } else {
                pos.push_back(i);
            }
        }

        int s = 0, e = 100001;
        int ans = 0;
        while(s <= e) {
            int m = (s + e) / 2;
            if(flow(m)) {
                s = m + 1;
                ans = m;
            } else e = m - 1;
        }
        cout << ans << '\n';
    }
    return 0;
}