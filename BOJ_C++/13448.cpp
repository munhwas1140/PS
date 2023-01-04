#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
struct asdf {
    int m, p, r;
};

int main() {
    fastio;
    int n, t;
    cin >> n >> t;
    vector<asdf> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].m;
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i].p;
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i].r;
    }

    return 0;
}