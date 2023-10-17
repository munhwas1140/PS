#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, k;
vector<int> a;
int dp[200][200];
int go(int s, int e) {
    if(s >= e) return 0;

    int &ret = dp[s][e];
    if(ret != -1) return ret;
    ret = 1e9;

    // if(a[s] == a[e]) {
    //     ret = 1 + go(s + 1, e - 1);
    //     for(int i = s + 1; i < e; i++) {
    //         if(a[i] == a[s]) {
    //             ret = min(ret, go(s, i) + go(i, e));
    //         }
    //     }
    // } else {
    //     for(int i = s; i < e; i++) {
    //         ret = min(ret, go(s, i) + go(i + 1, e) + 1);
    //     }
    // }

    for(int i = s; i < e; i++) {
        ret = min(ret, go(s, i) + go(i + 1, e) + (a[s] != a[i + 1]));
    }
    return ret;
}
int main() {
    fastio;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        if(a.empty() || a.back() != tmp) {
            a.push_back(tmp);
        }
    }

    n = a.size();
    memset(dp,-1,sizeof(dp));
    cout << go(0, n - 1) << '\n';

    return 0;
}