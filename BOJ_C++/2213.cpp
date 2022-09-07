#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
int n;
int a[10001];
vector<int> g[10001];
vector<int> child[10001];
int dp[10001][2];
bool visited[10001];
vector<int> ans;
void DFS(int now) {
    visited[now] = true;
    for(int &next : g[now]) {
        if(!visited[next]) {
            child[now].push_back(next);
            DFS(next);
        }
    }
}

int go(int now, int prev) {
    int &ret = dp[now][prev];
    if(ret != -1) return ret;
    int pick = -1e9, notpick = 0;
    for(int &next : child[now]) {
        notpick += go(next,0);
    }
    if(!prev) {
        pick = a[now];
        for(int &next : child[now]) {
            pick += go(next, 1);
        }
    }
    return ret = max(pick, notpick);
}
void tracking(int now, int prev) {
    
    int notpick = 0, pick = -1e9;
    for(int &next : child[now]) {
        notpick += go(next, 0);
    }
    if(!prev) {
        pick = a[now];
        for(int &next : child[now]) {
            pick += go(next, 1);
        }
    }

    if(notpick < pick) {
        ans.push_back(now);
        for(int &next : child[now]) {
            tracking(next, 1);
        }
    } else {
        for(int &next : child[now]) {
            tracking(next, 0);
        }
    }
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
    DFS(1);

    memset(dp,-1,sizeof(dp));
    cout << go(1,0) << '\n';
    tracking(1,0);
    sort(ans.begin(), ans.end());
    for(int &i : ans) {
        cout << i << ' ';
    }
    return 0;
}