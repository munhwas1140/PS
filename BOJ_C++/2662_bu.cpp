#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int v[21][301];
int dp[21][301];
int to[21][301];
int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
        int tmp; cin >> tmp;
        for(int j = 1; j <= m; j++) {
            cin >> v[j][i];
        }
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            for(int k = 0; k <= j; k++) {
                int val = dp[i - 1][j - k] + v[i][k];
                if(val > dp[i][j]) {
                    dp[i][j] = val;
                    to[i][j] = k;
                }
            }
        }
    }

    cout << dp[m][n] << '\n';
    int now = n;
    stack<int> st;
    for(int i = m; i >= 1; i--) {
        st.push(to[i][now]);
        now -= to[i][now];
    }

    while(!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }

    return 0;
}