#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int a[11];
int main() {
    fastio;
    memset(a,-1,sizeof(a));

    int n; cin >> n;

    int ans = 0;
    for(int i = 0; i < n; i++) {
        int num, t;
        cin >> num >> t;
        if(a[num] != -1 && a[num] != t) {
            ans++;
        }
        a[num] = t;
    }
    cout << ans << '\n';

    return 0;
}