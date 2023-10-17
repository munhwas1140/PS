#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        int s, e, l, r, sum, maxsum;
        s = e = l = r = sum = 0;
        maxsum = 0;

        for(int i = 0; i < n; i++) {
            sum += a[i];
            if(maxsum < sum) {
                maxsum = sum;
                s = l;
                e = i;
            } 
            if (sum <= 0) {
                sum = 0;
                l = min(i + 1, n - 1);
            }
        }
        if(maxsum == 0) {
            s = -1;
            e = -1;
        }
        cout << maxsum << ' ' << s << ' ' << e << '\n';
    }

    return 0;
}