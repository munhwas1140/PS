#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int n;
vector<int> g[1000001];
vector<int> child[1000001];
int dp[1000001][2];
bool visited[1000001];
void DFS(int now) {
    visited[now] = true;
    for(int &next : g[now]) {
        if(!visited[next]) {
            child[now].push_back(next);
            DFS(next);
        }
    }
}
int go(int now, bool prev) {

    int &ret = dp[now][prev];
    if(ret != -1) return ret;

    int pick = 1, notpick = 1e9;
    
    for(int &next : child[now]) {
        pick += go(next,1);
    }
    
    if(prev) {
        notpick = 0;
        for(int &next : child[now]) {
            notpick += go(next,0); 
        }
    }
    return ret = min(pick, notpick);
}
void tracking(int now, int prev) {
    int notpick = 1e9, pick = 1;
    for(int &next : child[now]) {
        pick += go(next,1);
    }
    if(prev) {
        notpick = 0;
        for(int &next : child[now]) {
            notpick += go(next, 0);
        }
    }

    if(pick < notpick) {
        cout << now << "-> pick" << '\n';
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
    for(int i = 0; i < n - 1; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    DFS(1);
    memset(dp,-1,sizeof(dp));
    cout << go(1, 1) << '\n';
    // tracking(1, 1);
    return 0;
}