#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<ll> aa(28), bb(28);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 28; j++) {
            if(a[i] & (1 << j)) aa[j]++;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 28; j++) {
            if(b[i] & (1 << j)) bb[j]++;
        }
    }

    ll ans1 = 0;
    for(int i = 0; i < 28; i++) {
        ans1 += (aa[i]) * (bb[i]) * (1LL << i);
        ans1 %= 1999LL;
    }
    cout << ans1 << '\n';

    return 0;
}