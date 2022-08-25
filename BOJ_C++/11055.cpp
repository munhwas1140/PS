#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> dp(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }    

    int ans = 0;

    for(int i = 0; i < n; i++) {
        dp[i] = a[i];
        for(int j = 0; j < i; j++) {
            if(a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + a[i]);
            }
        }
        ans = max(ans,dp[i]);
    }
    cout << ans << '\n';
      
    return 0;
}