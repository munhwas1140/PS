#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using tii = tuple<int,int,int>;
int n, k;
struct asdf {
    ll id;
    int pos, time;
    const bool operator<(const asdf &v) const {
        if(time == v.time) {
            return pos < v.pos;
        }
        return  time > v.time;
    }
    asdf(int time, int pos, ll id) : time(time), pos(pos), id(id) {}
};
int main() {
    fastio;
    cin >> n >> k;
    vector<pair<ll, int>> a(n);
    for(auto &[id, w] : a) {
        cin >> id >> w;
    }

    priority_queue<tii, vector<tii>, greater<tii>> pq;
    for(int i = 1; i <= k; i++) {
        pq.push({0, i, 0});
    }

    priority_queue<asdf> ans;
    for(auto [id, w] : a) {
        auto [time, pos, x] = pq.top();
        pq.pop();
        pq.push({time + w, pos, id});
        ans.push(asdf(time + w, pos, id));
    }


    ll ret = 0;
    for(ll i = 1; i <= n; i++) {
        ret += i * ans.top().id;
        ans.pop();
    }
    cout << ret << '\n';

    return 0;
}