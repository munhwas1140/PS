#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
bool visited[101];
int dp[1001][1001];
int a[51], b[51], c[51];
int main() {
    fastio;
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    memset(dp,-1,sizeof(dp));
    
    function<int(int, int)> go = [&] (int x, int y) {
        
        int &ret = dp[x][y];
        if(ret != -1) return ret;
        ret = 0;

        vector<int> pos;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            if(x >= a[i] || y >= b[i]) {
                ret++;
                if(!visited[i]) {
                    visited[i] = true;
                    pos.push_back(i);
                    sum += c[i];
                }
            }
        }
        
        for(int i = 0; i <= sum; i++) {
            int nx = min(1000, x + i);
            int ny = min(1000, y + sum - i);
            ret = max(ret, go(nx, ny));
        }

        for(int tt : pos) visited[tt] = false;
        return ret;
    };

    cout << go(1, 1) << '\n';
    return 0;
}