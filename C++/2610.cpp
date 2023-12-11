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
int dist[101][101];
int p[101];
vector<int> same[101];
int find(int now) {
    if(p[now] < 0) return now;
    return p[now] = find(p[now]);
}
void set_union(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    p[y] = x;
}
int main() {
    fastio;
    memset(p,-1,sizeof(p));
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dist[i][j] = (i == j ? 0 : 1e9);
        }
    }
    for(int i = 0; i < m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        dist[t1][t2] = dist[t2][t1] = 1;
        set_union(t1, t2);
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        int x = find(i);
        same[x].push_back(i);
    }

    vector<int> ans;
    for(int i = 1; i <= n; i++) {
        if(same[i].size() > 0) {
            int minv = 1e9;
            int minidx = -1;
            for(int now : same[i]) {
                int tmp = -1;
                for(int j = 1; j <= n; j++) {
                    if(dist[now][j] != 1e9) {
                        tmp = max(tmp, dist[now][j]);
                    }
                }
                if(tmp < minv) {
                    minidx = now;
                    minv = tmp;
                }
            }
            
            ans.push_back(minidx);
        }
    }
    
    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for(int i : ans) cout << i << '\n';
    
    return 0;
}