#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int cross(vector<int> &a, int s, int m, int e) {
    int sum = 0;
    int lsum = -1e9;
    for(int i = m; i >= s; i--) {
        sum += a[i];
        if(sum > lsum) {
            lsum = sum;
        }
    }

    sum = 0;
    int rsum = -1e9;
    for(int i = m; i <= e; i++) {
        sum += a[i];
        if(sum > rsum) {
            rsum = sum;
        }
    }

    return max({lsum + rsum - a[m], lsum, rsum});
}
int go(vector<int> &a, int s, int e) {
    if(s == e) return a[s];
    int m = (s + e) / 2;
    return max(go(a,s,m), max(go(a,m+1,e), cross(a,s,m,e)));
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        int ret = go(a, 0, n-1);
        if(ret < 0) ret = 0;
        cout << ret << '\n';
    }

    return 0;
}