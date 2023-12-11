#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
int a[10001];
int dp[10001][2];
vector<int> g[10001];
int go(int now, int s, int pre) {
    int &ret = dp[now][s];
    if(ret != -1) return ret;
    
    ret = 0;
    if(s) ret = a[now];
    
    for(int &next : g[now]) {
        if(next == pre) continue;
        if(s == 1) {
            ret += go(next, 0, now);
        } else {
            ret += max(go(next, 1, now), go(next, 0, now));
        }
    }
    return ret;
}

vector<int> ans;
void trace(int now, int s, int pre) {
    if(s == 1) ans.push_back(now);

    for(int &next : g[now]) {
        if(next == pre) continue;
        if(s == 1) {
            trace(next, 0, now);
        } else { 
            if(go(next, 1, now) > go(next, 0, now)) {
                trace(next, 1, now);
            } else {
                trace(next, 0, now);
            }
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
    
    memset(dp,-1,sizeof(dp));
    int t1 = go(1, 1, -1);
    int t2 = go(1, 0, -1);
    if(t1 < t2) {
        cout << t2 << '\n';
        trace(1, 0, -1);
    } else {
        cout << t1 << '\n';
        trace(1, 1, -1);
    }
    sort(ans.begin(), ans.end());
    for(int x : ans) cout << x << ' ';
    cout << '\n';
    return 0;
}