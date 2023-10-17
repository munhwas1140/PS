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
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        a[i] *= -1;
        a[i] += tmp;
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        int now = a[i];
        if(now < 0) ans -= now;
        else ans += now;
        
        if(now > 0) {
            for(int j = i + 1; j < n; j++) {
                if(a[j] < 0) break;
                if(a[j] >= now) a[j] -= now;
                else {
                    now = a[j];
                    a[j] = 0;
                }
            }
        } else {
            for(int j = i + 1; j < n; j++) {
                if(a[j] > 0) break;
                if(a[j] <= now) a[j] -= now;
                else {
                    now = a[j];
                    a[j] = 0;
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}