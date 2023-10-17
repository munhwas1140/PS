#include <bits/stdc++.h>
using namespace std;
int a[4001];
int b, n;
int sum[4001];
int sqsum[4001];
double dp[4001][31];
double go(int idx, int num) {
    double &ret = dp[idx][num];
    if(ret != -1) return ret;
    ret = 1e18;
    if(idx == n + 1) {
        return 0;
    }

    if(num == 0) return 1e18;
    
    for(int i = 0; i <= n - idx; i++) {
        // i + 1 사이즈
        double xsq = sqsum[idx + i] - sqsum[idx - 1];
        double avg = (sum[idx + i] - sum[idx - 1]) / (double)(i + 1);
        double Sum = sum[idx + i] - sum[idx - 1];

        ret = min(ret, go(idx + i + 1, num - 1) + xsq - 2 * Sum * avg + avg * avg * (double)(i + 1));
    }
    return ret;    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> b >> n;

    for(int i = 0; i < 4001; i++) {
        for(int j = 0; j < 31; j++) {
            dp[i][j] = -1;
        }
    }
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        sqsum[i] = sqsum[i - 1] + a[i] * a[i];
    }
    
    cout << fixed << setprecision(6);
    cout << go(1, b) << '\n';

    return 0;
}