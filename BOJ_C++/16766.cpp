#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
vector<int> a;
int n, m, c;
bool check(int mid) {
    int cnt = 0, bus = 0;
    int diffmax = 0;
    int pre = -1;
    for(int i = 0; i < n; i++) {
        if(pre == -1) {
            cnt = 1;
            bus++;
            pre = a[i];
        } else {
            cnt++;
            if(cnt > c) {
                cnt = 1;
                diffmax = 0;
                bus++;
                pre = a[i];
            } else {
                int diff = a[i] - pre;
                diffmax = max(diffmax, diff);
                if(diffmax > mid) {
                    cnt = 1;
                    diffmax = 0;
                    bus++;
                    pre = a[i];
                }
            }
        }
    }
    return bus <= m;
}
int main() {
    fastio;
    cin >> n >> m >> c;
    a.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    
    int s, e;
    int ans = 1e9;
    s = 0, e = 1e9;
    while(s <= e) {
        int mid = (s + e) / 2;
        if(check(mid)) {
            ans = min(ans, mid);
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    cout << ans << '\n';
    return 0;
}