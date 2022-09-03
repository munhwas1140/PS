#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int n;
vector<int> g[1000001];
int dp[1000001][2];
bool visited[1000001];
int go(int now, int state) { 
    int &ret = dp[now][state];
    if(ret != -1) return ret;
    ret = (state ? 1 : 0);
    // cout << ret << '\n';
    visited[now] = true;
    for(int next : g[now]) {
        if(!visited[next]) {
            if(state == 1) {
                ret += min(go(next, 1), go(next, 0));
            } else {
                ret += go(next, 1);
            }
        }
    }
    visited[now] = false;
    return ret; 
}
int main() {
    fastio;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    memset(dp,-1,sizeof(dp));
    // cout << go(1,0) << ' ' << go(1,1) << '\n';
    cout << min(go(1,0), go(1,1)) << '\n';
    return 0;
}