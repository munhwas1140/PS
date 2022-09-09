#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
int n;
int dp[200001][21];
int main() {
    fastio;
    cin >> n;
      
    for(int i = 1; i <= n; i++) {
        cin >> dp[i][0];
    }

    for(int i = 1; i <= 20; i++) {
        for(int j = 1; j <= n; j++) {
            dp[j][i] = dp[dp[j][i-1]][i-1];
        }
    }
    
    int q;
    cin >> q;
    while(q--) {
        int a, b;
        cin >> a >> b;
        for(int i = 20; i >= 0; i--) {
            if(a & (1 << i)) {
                b = dp[b][i];
            }
        }
        cout << b << '\n';
    }
    return 0;
}