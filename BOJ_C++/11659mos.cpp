#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
struct asdf {
    int s, e, idx;
    asdf (int _s, int _e, int _idx) : s(_s), e(_e), idx(_idx) {}
    asdf () {}
};
int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> ans(m);
    vector<asdf> q(m);
    for(int i = 0; i < m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        q[i] = asdf(t1 - 1, t2, i);
    }

    int sq = sqrt(n);
    sort(q.begin(), q.end(), [&] (const asdf &u, const asdf &v) {
        if(u.s/sq == v.s/sq) {
            return u.e < v.e;
        }
        return u.s/sq < v.s/sq;
    });

    int s = q[0].s, e = q[0].e;
    int sum = 0;
    for(int i = s; i < e; i++) {
        sum += a[i];
    }

    ans[q[0].idx] = sum;
    
    for(int i = 1; i < m; i++) {
        int ns = q[i].s;
        int ne = q[i].e;
        while(e < ne) sum += a[e++];
        while(ne < e) sum -= a[--e];
        while(s < ns) sum -= a[s++];
        while(ns < s) sum += a[--s];
        ans[q[i].idx] = sum;
    }

    for(int i = 0; i < m; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}