#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int tc; cin >> tc;
    for(int TC = 1; TC <= tc; TC++) {
        int n; cin >> n;
        deque<int> dq;
        for(int i = 0; i < n; i++) {
            int tmp; cin >> tmp;
            dq.push_back(tmp);
        }

        int mx = -1;
        int ans = 0;
        while(!dq.empty()) {
            if(dq.front() < dq.back()) {
                if(dq.front() >= mx) {
                    ans++;
                }
                mx = max(dq.front(), mx);
                dq.pop_front();
            } else {
                if(dq.back() >= mx) {
                    ans++;
                }
                mx = max(dq.back(), mx);
                dq.pop_back();
            }
        }
        cout << "Case #" << TC << ": " << ans << '\n';
    }

    return 0;
}