#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n, m = 0;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        m = max(m, a[i]);
    }
    
    vector<int> minp(m + 1);
    for(int i = 2; i <= m; i++) {
        if(!minp[i]) {
            minp[i] = i;
            for(int j = i + i; j <= m; j += i) {
                if(minp[j] == 0) minp[j] = i;
            }
        }
    }

    int s, t;
    cin >> s >> t;
    s--; t--;

    vector<vector<int>> g(m + 1);
    for(int i = 0; i < n; i++) {
        for(int x = a[i]; x > 1; x /= minp[x]) {
            g[minp[x]].push_back(i);
        }
    }


    vector<int> dist(n + m + 1, -1), prev(n + m + 1);
    queue<tuple<int,int,int>> q;
    q.push({s, 0, -1});

    while(!q.empty()) {
        auto [now, d, p] = q.front();
        q.pop();

        if(dist[now] != -1) continue;

        dist[now] = d;
        prev[now] = p;
    
        if(now < n) {
            for(int x = a[now]; x > 1; x /= minp[x]) {
                q.push({n + minp[x], d + 1, now});
            }
        } else {
            for(int x : g[now - n]) {
                q.push({x, d + 1, now});
            }
        }
    }

    vector<int> ans;

    if(dist[t] == -1) {
        cout << -1 << '\n';
    } else {
        for(int x = t; x != -1; x = prev[x]) {
            if(x < n) {
                ans.push_back(x);
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for(int &x : ans) {
            cout << x + 1 << ' ';
        }
        cout << '\n';
    }

    return 0;
}