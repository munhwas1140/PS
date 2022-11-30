#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
struct RNG {
    unsigned int s;
    RNG() : s(1983) {};
    unsigned next() {
        unsigned ret = s;
        s = s * 214013u + 2531011u ;
        
        return ret % 10000 + 1;
    }
};
void solve() {
    int k, n;
    cin >> k >> n;
    RNG rng;
    queue<int> q;
    int sum = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        int now = rng.next();
        sum += now;
        q.push(now);

        while(sum > k) {
            sum -= q.front();
            q.pop();
        }
        
        if(sum == k) ans++;
    }
    cout << ans << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}