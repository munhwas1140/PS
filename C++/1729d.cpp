#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;

int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            a[i] *= -1;
        }
        for(int i = 0; i < n; i++) {
            int tmp; cin >> tmp;
            a[i] += tmp;
        }
        sort(a.begin(), a.end());
        int l = 0, r = n - 1;
        int ans = 0;
        while(l < r) {
            if(a[l] + a[r] < 0) {
                l++;
            } else {
                l++; r--;
                ans += 1;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}