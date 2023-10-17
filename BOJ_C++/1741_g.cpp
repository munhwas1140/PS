#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
vector<int> g[10001];
int dist[10][10001];
void bfs(int s, int idx) {
    queue<int> q;
    q.push(s);
    dist[idx][s] = 0;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(int &next : g[now]) {
            if(dist[idx][next] == -1) {
                dist[idx][next] = dist[idx][now] + 1;
                q.push(next);
            }
        }
    }
    return ;
}
void solve() {
    for(int i = 0; i < 10001; i++) {
        g[i].clear();
        for(int j = 0; j < 10; j++) {
            dist[j][i] = -1;
        }
    }
    int n, m, f, k;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    cin >> f;
    vector<bool> cars(f + 1);
    vector<int> h(f + 1);
    for(int i = 1; i <= f; i++) {
        cin >> h[i];
        cars[i] = true;
    }
    cin >> k;
    vector<int> p(k + 1);
    vector<int> pp;
    for(int i = 1; i <= k; i++) {
        cin >> p[i];
        pp.push_back(i);
        cars[p[i]] = false;
    }

    bfs(1,0);
    for(int i = 1; i <= k; i++) {
        bfs(h[p[i]], i);
    }
    int ans = k;

    do {
        int lst = 0;
        for(int i = 1; i <= f; i++) {
            if(!cars[i]) continue;
            int d = dist[0][h[i]], tmp = 1;
            while(lst < k && dist[pp[lst]][tmp] + dist[pp[lst]][h[i]] == d) {
                d -= dist[pp[lst]][tmp];
                tmp = h[p[pp[lst]]];
                lst++;
            }
        }
        ans = min(ans, k - lst);
    } while(next_permutation(pp.begin(), pp.end()));

    cout << ans << '\n';
    return ;
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}