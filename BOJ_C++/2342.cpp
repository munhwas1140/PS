#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
int a[100010];
int dp[5][5][100010];
int moving[5][5];
int go(int l, int r, int idx) {
    if(idx == n) return 0;

    int &ret = dp[l][r][idx];
    if(ret != -1) return ret;

    int next = a[idx];
    ret = 1e9;
    
    if(r == next) {
        ret = min(ret, go(l, r, idx + 1) + 1);
    } else if(l == next) {
        ret = min(ret, go(l, r, idx + 1) + 1);
    } else {
        ret = min(go(next, r, idx + 1) + moving[l][next], go(l, next, idx + 1) + moving[r][next]);
    }
    return ret;
}
int main() {
    fastio;
    
    int tmp;
    while(true) {
        cin >> tmp;
        if(tmp == 0) break;
        a[n++] = tmp;
    }

    for(int i = 1; i <= 4; i++) {
        moving[0][i] = moving[i][0] = 2;
        moving[i][i] = 1;
        int next = i + 1;
        if(next == 5) next = 1;
        moving[i][next] = moving[next][i] = 3;
    }
    moving[1][3] = moving[3][1] = moving[4][2] = moving[2][4] = 4;

    memset(dp,-1,sizeof(dp));
    cout << go(0, 0, 0) << '\n';


    return 0;
}