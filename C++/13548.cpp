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
int a[100001], cnt[100001], ans[100001];
int cnt2[100001];
int bucket[400];
Query q[100001];
void update(int idx, int val) {
    int now = cnt[a[idx]];
    if(cnt2[now]) cnt2[now]--;
    if(bucket[now/sq]) bucket[now/sq]--;

    cnt[a[idx]] += val;
    cnt2[cnt[a[idx]]]++;
    bucket[cnt[a[idx]]/sq]++;

}
int query() {
    for(int i = 399; i >= 0; i--) {
        if(bucket[i] == 0) continue;
        for(int j = sq - 1; j >= 0; j--) {
            if(cnt2[i * sq + j]) return i * sq + j;
        }
    }
    return 0;
}
int main() {
    fastio;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    cin >> m;

    for(int i = 0; i < m; i++) {
        cin >> q[i].s >> q[i].e;
        q[i].idx = i;
    }

    sort(q, q + m);
    
    int s = q[0].s, e = q[0].e;
    for(int i = s; i <= e; i++) {
        update(i,1);
    }

    ans[q[0].idx] = query();
    for(int i = 1; i < m; i++) {
        int ns = q[i].s, ne = q[i].e;
        while(ns < s) update(--s,1);
        while(e < ne) update(++e,1);
        while(s < ns) update(s++,-1);
        while(ne < e) update(e--,-1);
        ans[q[i].idx] = query();
    }

    for(int i = 0; i < m; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}