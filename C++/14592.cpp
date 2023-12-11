#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
struct asdf {
    int s, c, l, idx;
};
int main() {
    fastio;
    int n;
    cin >> n;
    vector<asdf> a(3);
    for(int i = 0; i < n; i++) {
        cin >> a[i].s >> a[i].c >> a[i].l;
        a[i].idx = i + 1;
    }

    sort(a.begin(), a.end(), [] (const asdf &u, const asdf &v) {
        if(u.s == v.s) {
            if(u.c == v.c) {
                return u.l < v.l;
            }
            return u.c < v.c;
        }
        return u.s > v.s;
    });
    cout << a[0].idx << '\n';

    return 0;
}