#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
int n;
ll m, p[100000];

ll find(ll x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}
ll set_union(ll x, ll y) {
    x = find(x);
    y = find(y);
    if(x == y) return p[x];
    p[y] += p[x];
    p[x] = y;
    return p[y];
}
struct asdf{
    int idx;
    ll f, s;
    bool operator<(const asdf &v) const {
        return s < v.s;
    }
};

int main() {
    fastio;
    cin >> n >> m;
    vector<asdf> a(n);
    vector<asdf> b(n);
    for(int i = 0; i < n; i++) {
        auto &[idx, f, s] = a[i];
        idx = i; cin >> f >> s;
        b[i] = a[i];
        p[i] = -f;
    }         

    sort(b.begin(), b.end());

    for(int i = 0; i < n; i++) {
        auto &[idx, f, s] = b[i];
        if(idx > 0 && a[idx-1].s <= a[idx].s) {
            set_union(idx, idx - 1);
        }
        if(idx < n - 1 && a[idx + 1].s <= a[idx].s) {
            set_union(idx + 1, idx);
        } 
        if(p[find(idx)] <= -m) return !(cout << s << '\n');
    }
    return 0;
}