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
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    
    int s, e;
    s = e = 0;

    int tmp = 0;
    int mn = 1e9;
    while(e < n && s <= e) {
        int remain = n - (e - s + 1);
        if(tmp < remain) {
            e++;
            if(e < n) {
                tmp += a[e] - a[e - 1] - 1;
            }
        } else {
            if(tmp == remain) mn = min(mn, remain);
            else mn = min(mn, remain + 1);
            tmp -= a[s + 1] - a[s] - 1;
            s++;
        }
    }

    int mx = 0;
    for(int i = 0; i < n - 1; i++) {
        mx += a[i + 1] - a[i] - 1;
    }
    if(a[1] - a[0] != 1 && a[n - 1] - a[n - 2] != 1) {
        mx -= min(a[1] - a[0] - 1, a[n - 1] - a[n - 2] - 1);
    }
    cout << mn << '\n' << mx << '\n';

    return 0;
}