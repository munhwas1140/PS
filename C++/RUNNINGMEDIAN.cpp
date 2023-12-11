#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll MOD = 20090711;
int n;
ll a, b;
int next(int x) {
    return ((ll)x * a + b) % MOD;
}
void solve() {
    cin >> n >> a >> b;
    int ans = 0;
    priority_queue<int> lpq;
    priority_queue<int,vector<int>, greater<int>> rpq;
    int st = 1983;
    
    for(int i = 0; i < n; i++) {
        if(lpq.empty()) {
            lpq.push(st);
        } else {
            if(lpq.size() > rpq.size()) {
                if(st < lpq.top()) {
                    rpq.push(lpq.top());
                    lpq.pop();
                    lpq.push(st);
                } else rpq.push(st);
            } else {
                if(st > rpq.top()) {
                    lpq.push(rpq.top());
                    rpq.pop();
                    rpq.push(st);
                } else lpq.push(st);
            }
        }


        ans += lpq.top();
        ans %= MOD;
        st = next(st);
    }
    cout << ans << '\n';
    return ;
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}