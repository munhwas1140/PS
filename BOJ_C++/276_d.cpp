#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int main() {
    fastio;
    int n; cin >> n;

    vector<int> a(n);
    int tmp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i == 0) tmp = a[i];
        else tmp = gcd(a[i], tmp);
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        a[i] /= tmp;
        
        while(a[i] % 2 == 0) {
            a[i] /= 2;
            ans++;
        }

        while(a[i] % 3 == 0) {
            a[i] /= 3;
            ans++;
        }

        if(a[i] != 1) return !(cout << -1 << '\n');
    }
    cout << ans << '\n';

    return 0;
}