#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int a[101];
int dp[101];
int main() {
    fastio;
    int n; cin >> n;
    
    for(int i = 0; i < n; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        if(t1 > t2) swap(t1, t2);
        a[t1] = t2;
    }



    for(int i = 0; i < 101; i++) {
        if(a[i] == 0) continue;
        int &ret = dp[i];
        ret = 1;
        int e = a[i];
        int ne = a[i];
        for(int j = i + 1; j < e; j++) {
            if(a[j] == 0) continue;
            if(a[j] < ne) {
                ne = a[j];
                ret++;
            }
        }
    }

    int ans = 1;
    for(int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
        for(int j = i + 1; j < n; j++) {
            if(a[j].first > a[i].second && (a[j].second < a[i].first || a[j].second > a[i].second)) {
                ans = max(ans, dp[i] + dp[j]);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}