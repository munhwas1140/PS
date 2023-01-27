#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, k, m;
int sq = sqrt(100000);
int a[100001], ans[100001];
int cnt[100001], bucket[350];
list<int> li[100001];
struct Query {
    int s, e, idx;
    Query() {}
    bool operator <(const Query &q) const {
        if(s/sq == q.s/sq) return e < q.e;
        return s/sq < q.s/sq;
    }
};

Query q[100001];
void add(int val, int idx, int flag) {
    int now;
    auto &dq = li[val];
    if(!dq.empty()) {
        now = dq.back() - dq.front();
        cnt[now]--; bucket[now/sq]--;
    }

    if(flag) dq.push_back(idx);
    else dq.push_front(idx);

    now = dq.back() - dq.front();
    cnt[now]++; bucket[now/sq]--;
}
void del(int val, int idx, int flag) {
    auto &dq = li[val];
    int now = dq.back() - dq.front();
    cnt[now]--; bucket[now/sq]--;

    if(flag) dq.pop_back();
    else dq.pop_front();
    
    if(!dq.empty()) {
        now = dq.back() - dq.front();
        cnt[now]++; bucket[now/sq]++;
    }
}


int query() {
    for(int i = 349; i >= 0; i--) {
        if(bucket[i] == 0) continue;
        for(int j = sq - 1; j >= 0; j--) {
            if(cnt[i * sq + j]) return i * sq + j;
        }
    }
    return 0;
}
int main() {
    fastio;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> q[i].s >> q[i].e;
        q[i].idx = i;
    }

    sort(q, q + m);

    
    int s = q[0].s, e = q[0].e;

    for(int i = s; i <= e; i++) {
        add(a[i], i, 1);
    }
    ans[q[0].idx] = query();

    for(int i = 1; i < m; i++) {
        int ns = q[i].s, ne = q[i].e;
        while(ns < s) {
            s--;
            add(a[s], s, 0);
        }
        while(e < ne) {
            e++;
            add(a[e], e, 1);
        }
        while(s < ns) {
            del(a[s], s, 0);
            s++;
        }
        while(ne < e) {
            del(a[e], e, 1);
            e--;
        }
        ans[q[i].idx] = query();
    }
    
    for(int i = 0; i < m; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}