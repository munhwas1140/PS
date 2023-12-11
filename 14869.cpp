#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m, s, e, t;
int a[3000][3000];
int dp[3000][3000];
int main() {
    fastio;
    cin >> n >> m >> s >> e >> t;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    memset(dp, -1,sizeof(dp));
    
    vector<deque<int>> dq(n);
    
    for(int i = 0; i < m; i++) [
        for(int j = 0; j < n; j++) {

            while(!dq[j].empty && dq[j].front() < i - e) dq[j].pop_front();
            

        }
    ]





    return 0;
}