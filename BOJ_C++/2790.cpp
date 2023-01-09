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
    int mx = -1e9;
    int v;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++) {
        if(a[i] + n - i > mx) {
            mx = a[i] + n - i;
            v = a[i];
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] + n >= mx || a[i] == v) {
            ans++;
        } 
    }
    cout << ans << '\n';


    return 0;
}