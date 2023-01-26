#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
struct asdf {
    int s, e, idx;
    asdf(int _s, int _e, int _idx) : s(_s), e(_e), idx(_idx) {}
};
int main() {
    fastio;
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int m; cin >> m;
    vector<asdf> q;
    for(int i = 0; i < m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        q.push_back(asdf(t1 - 1, t2, i));
    }

    vector<int> ans(m);
    
    int sq = sqrt(n);
    sort(q.begin(), q.end(), [&] (const asdf &u, const asdf &v) {
        if(u.s/sq == v.s/sq) return u.e < v.e;
        return u.s/sq < v.s/sq;
    });

    int s = q[0].s, e = q[0].e;
    vector<int> cnt(1000001);
    int sum = 0;
    for(int i = s; i < e; i++) {    
        cnt[a[i]]++;
        if(cnt[a[i]] == 1) sum++;
    }
    ans[q[0].idx] = sum;

    for(int i = 1; i < m; i++) {
        int ns = q[i].s, ne = q[i].e;

        while(s < ns) {
            cnt[a[s++]]--;
            if(cnt[a[s - 1]] == 0) sum--;
        }
        while(ns < s) {
            cnt[a[--s]]++;
            if(cnt[a[s]] == 1) sum++;
        }
        while(e < ne) {
            cnt[a[e++]]++;
            if(cnt[a[e - 1]] == 1) sum++;
        }
        while(ne < e) {
            cnt[a[--e]]--;
            if(cnt[a[e]] == 0) sum--;
        }
        ans[q[i].idx] = sum;
    }

    for(int i = 0; i < m; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}