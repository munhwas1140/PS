#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    ll n; cin >> n;
    vector<ll> a(6);
    for(int i = 0; i < 6; i++) {
        cin >> a[i];
    }
    ll mn = *min_element(a.begin(), a.end());
    ll mn2 = 1e9;
    for(int i = 0; i < 6; i++) {
        for(int j = i + 1; j < 6; j++) {
            if((i == 0 && j == 5) || (i == 1 && j == 4) || (i == 2 && j == 3)) continue;
            mn2 = min(mn2, a[i] + a[j]);
        }
    }

    int t[8][3] = {{0, 1, 2}, {0, 1, 3}, {0, 3, 4}, {0, 4, 2}, {5, 1, 2}, {5, 1, 3}, {5, 3, 4}, {5, 4, 2}};
    ll mn3 = 1e9;
    for(int i = 0; i < 8; i++) {
        ll tmp = 0;
        for(int j = 0; j < 3; j++) {
            tmp += a[t[i][j]];
        }
        mn3 = min(mn3, tmp);
    }

    if(n == 1) {
        cout << accumulate(a.begin(), a.end(), 0LL) - *max_element(a.begin(), a.end()) << '\n';
    } else if(n == 2) {
        cout << 4 * mn2 + 4 * mn3 << '\n';
    } else {
        ll t1 = (n - 2) * (n - 2) * mn;
        ll t2 = (n - 2) * (n - 1) * mn * 4;
        ll t3 = mn3 * 4;
        ll t4 = (n - 1) * 4 * mn2 + (n - 2) * 4 * mn2;
        cout << t1 + t2 + t3 + t4 << '\n';
    }

    return 0;
}