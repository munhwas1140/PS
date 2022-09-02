#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int n;
int a[10001];
int dp[10001][2];
bool visited[10001];
vector<int> g[10001];

int go(int now, int state) {
    
    int &ret = dp[now][state];
    if(ret != -1) return ret;
    visited[now] = true; 
    ret = 0;
    
    for(int next : g[now]) {
        if(!visited[next]) { 
            int t1 = go(next, 0);
            int t2 = 0;
            if(state == 0) {
                t2 = go(next, 1);
            }
            ret = max(t1, t2);
        }
    }
    visited[now] = false;
    ret += state ? a[now] : 0;
    return ret;
}
int main() {
    fastio;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n - 1; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }

    memset(dp,-1,sizeof(dp));
    cout << go(1, 0) << ' ' << go(1, 1) << '\n';
    cout << max(go(1, 0), go(1, 1)) << '\n';
    return 0;
}