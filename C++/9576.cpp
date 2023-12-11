#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
pii a[1001]; 
int l[1001];
int r[1001];
bool visited[1001];
bool dfs(int now) {
    visited[now] = true;
    for(int i = a[now].first; i <= a[now].second; i++) {
        if(r[i] == -1 || !visited[r[i]] && dfs(r[i])) {
            r[i] = now;
            l[now] = i;
            return true;
        }
    }
    return false;
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        cin >> m >> n;
        memset(l,-1,sizeof(l));
        memset(r,-1,sizeof(r));
        
        for(int i = 1; i <= n; i++) {
            cin >> a[i].first >> a[i].second;
        }
    
        int match = 0;
        for(int i = 1; i <= n; i++) {
            if(l[i] == -1) {
                memset(visited,false,sizeof(visited));
                if(dfs(i)) match++;
            }
        }
        cout << match << '\n';
    }

    return 0;
}