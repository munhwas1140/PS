#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int main() {
    fastio;
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    int idx = -1;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] > k) a[i] = 1;
        else if(a[i] < k) a[i] = -1;
        else if(a[i] == k) {
            a[i] = 0;
            idx = i;
        }
    }
    map<int,int> mp;
    int s = 0;
    for(int i = idx; i >= 0; i--) {
        s += a[i];
        ++mp[s];
    }
    s = 0;

    int ans = 0;
    for(int i = idx; i < n; i++) {
        s += a[i];
        ans += mp[-s];
    }
    cout << ans << '\n';
    return 0;
}