#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        int n, idx;
        cin >> n >> idx;
        queue<pii> q;
        for(int i = 0; i < n; i++) {
            int tmp; cin >> tmp;
            q.push({tmp, i});
        }
        int cnt = 1;
        while(!q.empty()) {
            int now = q.front().first;
            int sz = (int)q.size();
            bool ok = true;
            while(sz--) {
                auto p = q.front();
                if(p.first > now) ok = false;
                q.pop();
                q.push(p);
            }
            if(ok == false) {
                q.push(q.front()); q.pop();
            } else {
                if(q.front().second == idx) {
                    cout << cnt << '\n';
                    break;
                }
                q.pop();
                cnt++;
            }
        }
    }

    return 0;
}