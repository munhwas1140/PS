#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string a, b;
    cin >> a >> b;
    a = " " + a;
    b = " " + b;
    int ans = 0;
    pair<int,int> idx;
    for(int i = 1; i < a.size(); i++) {
        for(int j = 1; j < b.size(); j++) {
            int k = (a[i] == b[j]);
            if(k) {
                dp[i][j] = dp[i-1][j-1] + k;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
            if(ans < dp[i][j]) {
                ans = dp[i][j];
                idx = make_pair(i,j);
            }
        }
    }
    
    if(ans) {
        cout << ans << '\n';
        int x = idx.first;
        int y = idx.second;
        int num = dp[x][y];
        string ansStr = "";
        ansStr = a[x];
        while(num != 1) {
            x -= 1;
            y -= 1;
            num = dp[x][y]; 
            while(dp[x-1][y] == num) x-= 1;
            while(dp[x][y-1] == num) y-= 1;
            ansStr = a[x] + ansStr;
        }
        cout << ansStr << '\n';
    } else {
        cout << 0 << '\n';
    }
    return 0;
}