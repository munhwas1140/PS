#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    int tmp = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        tmp |= a[i];
    }

    int s = 0, e = n;
    int now = 0;
    for(int i = 0; i < n; i++) {
        now |= a[i];
        if(now == tmp) {
            s = i + 1;
            break;
        }
    }
    int ans = 1e9;
    while(s <= e) {
        int m = (s + e) / 2;
        bool f = true;
        vector<int> cnt(20);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 20; j++) {
                if(a[i] & 1 << j) {
                    cnt[j]++;
                }
            }
            if(i - m >= 0) {
                for(int j = 0; j < 20; j++) {
                    if(a[i - m] & 1 << j) {
                        cnt[j]--;
                        if(cnt[j] == 0) {
                            if(tmp & 1 << j) {
                                f = false;
                                break;
                            }
                        }
                    }
                    if(!f) break;
                }
            }
            if(!f) break;
        }
        if(f) {
            ans = m;
            e = m - 1;
        } else {
            s = m + 1;
        }
    }
    cout << ans << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}