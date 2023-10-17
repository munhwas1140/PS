#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int d[1001], b[1001];
int cnt[1001];
int main() {
    fastio;
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cnt[1] = 1;
    b[1] = 1;
    for(int i = 2; i <= 1000; i++) {
        if(i % 2) {
            cnt[i] = cnt[i - 1] + 1;
            b[i] = b[i - 1] + 1;
            d[i] = d[i - 1];
        } else {
            if(cnt[i - 1] >= cnt[i / 2]) {
                cnt[i] = cnt[i / 2] + 1;
                d[i] = d[i / 2] + 1;
                b[i] = b[i / 2];
            } else {
                cnt[i] = cnt[i - 1] + 1;
                b[i] = b[i - 1] + 1;
                d[i] = d[i - 1];
            }
        }
    }

    int mx = -1;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        mx = max(mx, d[a[i]]);
        ans += b[a[i]];
    }

    cout << mx + ans << '\n';

    return 0;
}