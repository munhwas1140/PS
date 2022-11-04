#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll INF = 1e18;
int n, d;
ll a[100001];
ll dp[100001];
int main() {
    fastio;
    cin >> n >> d;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        dp[i] = -INF;
    }
    ll res = -INF;
    deque<int> dq;
    
    for(int i = 0; i < n; i++) {
        while(!dq.empty()) {
            if(dq.front() < i - d) dq.pop_front();
            else break;
        }

        dp[i] = (dq.empty() || dp[dq.front()] < 0 ? 0 : dp[dq.front()]) + a[i];
        res = max(dp[i], res);

        while(!dq.empty()) {
            if(dp[dq.back()] <= dp[i]) dq.pop_back();
            else break;
        }
        dq.push_back(i);
    }
    cout << res << '\n';
    return 0;
}