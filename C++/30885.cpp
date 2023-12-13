#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    deque<pll> q;
    for(int i = 0; i < n; i++) {
        ll tmp; cin >> tmp;
        q.push_back({tmp, i + 1});
    }

    while(q.size() > 1) {
        deque<pll> nq;
        while(q.size() > 1) {
            auto [t1, i1] = q.front(); q.pop_front();
            auto [t2, i2] = q.front(); q.pop_front();
            ll next = t1 + t2;
            int ni;
            if(t1 >= t2) ni = i1;
            else ni = i2;
            while(!q.empty()) {
                auto [t3, i3] = q.front(); q.pop_front();
                if(t3 >= next) {
                    next += t3;
                    ni = i3;
                } else {
                    q.push_front({t3, i3});
                    break;
                }
            }
            nq.push_back({next, ni});
        }
        if(!q.empty()) {
            nq.push_back(q.front());
            q.pop_back();
        }
        q = nq;
    }
    cout << q.front().first << '\n' << q.front().second << '\n';
    return 0;
}