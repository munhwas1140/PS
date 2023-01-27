#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int sq = sqrt(100000);
struct Query {
    int s, e, idx;
    Query() {}
    bool operator <(const Query &q) const {
        if(s/sq == q.s/sq) return e < q.e;
        return s/sq < q.s/sq;
    }
};

int n, m;
vector<ll> a;
ll cnt[1000001];
int main() {
    fastio;
    cin >> n >> m;
    a.resize(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<Query> q(m);
    for(int i = 0; i < m; i++) {
        cin >> q[i].s >> q[i].e;
        q[i].idx = i;
    }
    sort(q.begin(), q.end());

    ll sum = 0;

    function<void(int, int )> update = [&] (int idx, int val) {
        sum -= cnt[a[idx]] * cnt[a[idx]] * a[idx];
        cnt[a[idx]] += val;
        sum += cnt[a[idx]] * cnt[a[idx]] * a[idx];
    };

    vector<ll> ans(m);

    int s = q[0].s, e = q[0].e;
    for(int i = s; i <= e; i++) {
        update(i, 1);
    }
    ans[q[0].idx] = sum;

    for(int i = 1; i < m; i++) {
        int ns = q[i].s, ne =   q[i].e;
        while(ns < s) update(--s,1);
        while(e < ne) update(++e,1);
        while(s < ns) update(s++,-1);
        while(ne < e) update(e--,-1);
        ans[q[i].idx] = sum;
    }

    for(int i = 0; i < m; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}