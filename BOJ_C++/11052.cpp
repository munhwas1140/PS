// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// int a[1001];
// int dp[1001][1001];
// int n;
// int go(int idx, int sum) {
//     if(sum < 0) return -1e9;
//     if(idx == n + 1) {
//         return (sum == 0 ? 0 : -1e9);
//     }

//     int &ret = dp[idx][sum];
//     if(ret != -1) return ret;

//     ret = go(idx + 1, sum);
//     ret = max(ret, go(idx, sum - idx) + a[idx]);
//     return ret;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);

//     cin >> n;
//     for(int i = 1; i <= n; i++) {
//         cin >> a[i];
//     }
//     memset(dp,-1,sizeof(dp));
//     cout << go(1,n) << '\n';
     
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[1001];
int d[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            if(j - i >= 0) {
                d[j] = max(d[j], d[j-i] + a[i]);
            }
        }
    }

    cout << d[n] << '\n';

    return 0;
}