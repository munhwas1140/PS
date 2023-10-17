#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll NEGINF = numeric_limits<ll>::min();
int n, m;
int a[101];
int b[101];
int dp[101][101];
int jlis(int indexA, int indexB) {

    int &ret = dp[indexA + 1][indexB + 1];
    if(ret != -1) return ret;

    ret = 2;
    ll A = (indexA == -1 ? NEGINF : a[indexA]);
    ll B = (indexB == -1 ? NEGINF : b[indexB]);

    ll maxElement = max(A, B);

    for(int nextA = indexA + 1; nextA < n; nextA++) {
        if(maxElement < a[nextA]) {
            ret = max(ret, jlis(nextA, indexB) + 1);
        }
    }

    for(int nextB = indexB + 1; nextB < m; nextB++) {
        if(maxElement < b[nextB]) {
            ret = max(ret, jlis(indexA, nextB) + 1);
        }
    }
    return ret;
}
void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    memset(dp,-1,sizeof(dp));
    cout << jlis(-1, -1) - 2 << '\n';
    return ;
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}