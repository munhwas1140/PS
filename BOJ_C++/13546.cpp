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
    int n, k;
    cin >> n >> k;
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

    int sq = sqrt(n);

    sort(q.begin(), q.end(), [&] (const asdf &u, const asdf &v) {
        if(u.s/sq == v.s/sq) return u.e < v.e;
        return u.s/sq < v.s/sq;
    });

    
    list<int> li[k + 1];
    vector<int> ans(m);
    map<int,int> mp;
    int s = q[0].s, e = q[0].e;
    for(int i = s; i < e; i++) {
        if(!li[a[i]].empty()) {
            int now = li[a[i]].back() - li[a[i]].front();
            mp[now]--;
            if(mp[now] == 0) mp.erase(mp.find(now));
        }
        li[a[i]].push_back(i);
        mp[li[a[i]].back() - li[a[i]].front()]++;
    }

    ans[q[0].idx] = prev(mp.end())->first;

    for(int i = 1; i < m; i++) {
        int ns = q[i].s, ne = q[i].e;
        while(s < ns) {
            if(!li[a[s]].empty()) {
                int now = li[a[s]].back() - li[a[s]].front();
                mp[now]--;
                if(mp[now] == 0) mp.erase(mp.find(now));
            }
            li[a[s]].pop_front();
            s++;
        }
        while(ns < s) {
            li[a[--s]].push_front(s);
            int now = li[a[s]].back() - li[a[s]].front();
            mp[now]++;
        } 
        while(e < ne) {
            li[a[e]].push_back(e);
            int now = li[a[e]].back() - li[a[e]].front();
            mp[now]++;
            e++;
        }
        while(ne < e) {
            if(!li[a[e - 1]].empty()) {
                int now = li[a[e - 1]].back() - li[a[e - 1]].front();
                mp[now]--;
                if(mp[now] == 0) mp.erase(mp.find(now));
            }
            li[a[--e]].pop_back();
        }
        ans[q[i].idx] = prev(mp.end())->first;
    }

    for(int i = 0; i < m; i++) {
        cout << ans[i] << '\n';
    }
    
    return 0;
}