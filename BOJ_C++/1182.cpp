#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int a[20];
int n, s;
int go(int idx, int sum) {
    if(idx == n) return (sum == s ? 1 : 0);
    int ret = 0;
    ret += go(idx + 1, sum + a[idx]);
    ret += go(idx + 1, sum);
    return ret;
}
int main() {
    fastio;
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = go(0, 0);
    if(s == 0) ans -= 1;
    cout << ans << '\n';
      
    return 0;
}