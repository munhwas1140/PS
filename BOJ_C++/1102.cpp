#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int n, k;
int w[16][16];
int dp[16][1<<16];
int go(int cnt, int state) {
    if(cnt >= k) {
        return 0;
    }
    int &ret = dp[cnt][state];
    if(ret != -1) return ret;
    
    
    ret = 1e9;
    for(int i = 0; i < n; i++) {
        if(state & (1 << i)) {
            for(int j = 0; j < n; j++) {
                if((state & (1 << j)) == 0) {
                    ret = min(ret, go(cnt + 1, state | (1 << j)) + w[i][j]);
                }
            }
        }
    }
    return ret;
}
int main() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> w[i][j];
        }
    }
    string str;
    cin >> str >> k;

    int start = 0, cnt = 0;
    for(int i = 0; i < n; i++) {
        if(str[i] == 'Y') {
            start |= (1 << i);
            cnt += 1;
        }
    }
    memset(dp,-1,sizeof(dp));
    if(cnt >= k) cout << 0 << '\n';
    else {
        int ans = go(cnt, start);
        if(ans == 1e9) cout << -1 << '\n';
        else cout << ans << '\n'
    }

      
    return 0;
}