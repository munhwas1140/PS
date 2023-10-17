#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int mx = *max_element(a.begin(), a.end());
    int num[2][6] = {
        {0, 2, 1, 2, 3, 3},
        {0, 1, 2, 2, 3, 4}
    };
    ll ans = 0;
    int cnt[3] = {0};
    for(int i = 0; i < n; i++) {
        a[i] = mx - a[i];
        ans += (a[i] / 6) * 4;
        a[i] %= 6;
        if(a[i] == 3) {
            ans += 2;
            a[i] = 0;
        } else if(a[i] == 4) {
            ans += 3;
            a[i] = 0;
        }

        if(a[i] == 1) cnt[0]++;
        else if(a[i] == 2) cnt[1]++;
        else if(a[i] == 5) cnt[2]++;
    }
    int mn = min(cnt[0], cnt[1]);
    cnt[0] -= mn;
    cnt[1] -= mn;
    ans += mn * 2LL;
    if(cnt[0]) {
        mn = min(cnt[0], cnt[2]);
        cnt[0] -= mn;
        cnt[2] -= mn;
        ans += mn * 4LL;
        if(cnt[0]) {
            ans += cnt[0] * 2LL - 1;
        } else {
            ans += cnt[2] * 4LL;
        }
    } else {
        if(cnt[1] && cnt[2]) {
            mn = min(cnt[1], cnt[2]);
            cnt[1] -= mn;
            cnt[2] -= mn;
            ans += mn * 5LL;
            if(cnt[1]) {
                ans += cnt[1] * 2LL;
            } else {
                ans += 4LL * cnt[2];
            }
        } else if(cnt[1] && !cnt[2]) {
            ans += 2LL * cnt[1];
        } else if(cnt[2] && !cnt[1]) {
            ans += 4LL * cnt[2];
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