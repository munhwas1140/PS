#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
char s, e;
string str;
vector<int> g[1000002];
int p[1000002];

string rec(int i) {
    if(p[i] == -1) return string(1, s);
    return rec(p[i]) + str[i];
}

int main() {
    fastio;
    cin >> n >> m >> s >> e >> str;
    str.push_back(s); str.push_back(e);

    for(int i = 0; i < m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        t1--; t2--;

        if(str[t1] == s) t1 = n;
        if(str[t2] == s) t2 = n;

        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    
    if(s == e) {
        cout << s << '\n';
        return 0;
    }

    for(int i = 0; i <= n; i++) {
        sort(g[i].begin(), g[i].end(), [&](const int &u, const int &v) {
            return str[u] < str[v];
        });
    }

    queue<int> q;
    vector<int> dist(n + 1, -1);
    memset(p,-1,sizeof(p));
    dist[n] = 0;
    q.push(n);


    string ans = "";
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        
        for(int &next : g[now]) {
            if(str[next] == e) {
                string tmp = rec(now) + e;
                if(ans == "" || ans.size() > tmp.size() || (ans.size() == tmp.size() && ans > tmp)) {
                    ans = tmp;
                }
                continue;
            }

            if(dist[next] == -1) {
                p[next] = now;
                dist[next] = dist[now] + 1;
                q.push(next);
            }
        }
    }

    if(ans == "") cout << "Aaak!" << '\n';
    else cout << ans << '\n';

    return 0;
}