#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
ull Base[3] = {2, 7, 61};
ull Power(ull x, ull y, ull mod) { // ret = (x^y)%mod
    ull ret = 1;
    x %= mod;
    while(y) {
        if(y%2 == 1) ret = (ret*x)%mod;
        y /= 2;
        x = (x*x)%mod;
    }
    return ret;
}
bool isPrime(ull n, ull a) {
    if(a%n == 0) return true;
    ull k = n-1;
    while(1) {
        ull temp = Power(a, k, n);
        if(temp == n-1) return true;
        if(k%2 == 1) return (temp == 1 || temp == n-1);
        k /= 2;
    }
}

int n, m;
vector<pii> g[10001];
bool check(int mid) {
    vector<bool> visited(n + 1, false);
    queue<int> q;
    visited[1] = true;
    q.push(1);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(auto [next, cost] : g[now]) {
            if(mid > cost && !visited[next]) {
                q.push(next);
                visited[next] = true;
            }
        }
    }
    return visited[n];
}
int main() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        g[t1].push_back({t2, t3});
        g[t2].push_back({t1, t3});
    }

    int s, e;
    s = 2;
    e = 1e9 + 1;
    int ans = -1;
    while(s <= e) {
        int mid = (s + e) / 2;
        if(check(mid)) {
            ans = mid;
            e = mid - 1;
        } else s = mid + 1;
    }


    for(;;ans++) {
        int cnt = 0;
        for(int i = 0; i < 3; i++) {
            if(isPrime(ull(ans), Base[i])) cnt++;
        }
        if(cnt == 3) {
            return !(cout << ans << '\n');
        }
    }

    return 0;
}