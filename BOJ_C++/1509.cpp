#include <bits/stdc++.h>
using namespace std;
bool pel[2500][2500];
int dp[2500];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string str;
    cin >> str;

    int n = str.size();
    for(int i = 0; i < n; i++) pel[i][i] = true;
    for(int i = 0; i < n - 1; i++) if(str[i] == str[i + 1]) pel[i][i + 1] = true;
    for(int sz = 3; sz <= n; sz++) {
        for(int i = 0; i <= n - sz; i++) {
            if(str[i] == str[i + sz - 1] && pel[i + 1][i + sz - 1]) pel[i][i + sz - 1] = true;
        }
    }    

    for(int i = 0; i < n; i++) {
        dp[i] = 1e9;
        for(int j = 0; j <= i; j++) {
            if(pel[j][i]) {
                dp[i] = min(dp[i], (j > 0 ? dp[j - 1] : 0) + 1);
            }
            
        }
    }
    cout << dp[n-1];
    
    
    return 0;
}