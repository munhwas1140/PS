#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;

int ind[1001];
int n, m;
vector<int> g[1001];
int main() {
    fastio;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int k; cin >> k;
        int prev;
        for(int j = 0; j < k; j++) {
            int tmp; cin >> tmp;
            if(j > 0) {
                g[prev].push_back(tmp);
                ind[tmp] += 1;
            }
            prev = tmp;
        }
    }

    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(!ind[i]) q.push(i);
    }
    
    vector<int> ans;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        
        ans.push_back(now);
        for(int next : g[now]) {
            ind[next]--;
            if(ind[next] == 0) {
                q.push(next);
            }
        }
    }

    if(ans.size() != n) cout << 0 << '\n';
    else {
        for(int n : ans) {
            cout << n << '\n';
        }
    }

    return 0;
}
