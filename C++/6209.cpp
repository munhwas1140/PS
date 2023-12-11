#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int d, n, m;
vector<int> a;
int check(int dist) {
    int cnt = 0;

    int now = 0;
    for(int i = 0; i < n + 1; i++) {
        now += a[i + 1] - a[i];
        if(now < dist) cnt++;
        else now = 0;
    }
    
    return cnt;
}
int main() {
    fastio;
    cin >> d >> n >> m;
    a.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    a.push_back(0);
    a.push_back(d);

    sort(a.begin(), a.end());
    int l = 1, r = d;
    int ans = 1;

    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(mid) <= m) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << '\n';

    return 0;
}