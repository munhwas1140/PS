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
    for(int i = 0; i < n; i++) {
        string str; cin >> str;
        a[i] = (int)str.size();
    }

    ll cnt[21] = {0};
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        if(i - k - 1 >= 0) {
            cnt[a[i - k - 1]]--;
        }
        ans += cnt[a[i]];
        cnt[a[i]]++;
    }
    cout << ans << '\n';

    return 0;
}