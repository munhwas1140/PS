#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
string s1, s2;
int dp[101][101], S[101][101];

void init() {
    for(int i = 0; i < 101; i++) {
        for(int j = 0; j < 101; j++) {
            dp[i][j] = 0;
            S[i][j] = 0;
        }
    }
}

int MAX(int a, int b) {return (a > b ? a : b);}

void printLCS(int n, int m) {
    if(m == 0 || n == 0) return ;
    if(S[n][m] == 0) {
        printLCS(n - 1, m - 1);
        cout << s1[n - 1];
    } else if(S[n][m] == 1) printLCS(n, m - 1);
    else printLCS(n - 1, m);
}

void solve() {
    init();
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                S[i][j] = 0;
            } else {
                dp[i][j] = MAX(dp[i-1][j], dp[i][j - 1]);
                if(dp[i][j] == dp[i][j - 1]) {
                    S[i][j] = 1;
                } else {
                    S[i][j] = 2;
                }
            }
        }
    }

    cout << dp[n][m] << ' ';
    printLCS(n, m);
    cout << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}