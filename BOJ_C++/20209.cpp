#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, k;
vector<vector<int>> sw;
void turn(vector<int> &a, int idx) {
    for(auto &x : sw[idx]) {
        a[x] += (idx + 1);
        a[x] %= 5;
    }
}
int go(vector<int> &a, int idx) {
    if(idx == k) {
        for(int i = 1; i <= n; i++) {
            if(a[i] != a[1]) return 1e9;
        }
        return 0;
    }
    
    int ret = 1e9;
    
    for(int i = 1; i <= 4; i++) {
        turn(a, idx);
        ret = min(ret, i + go(a, idx + 1));
    }
    turn(a, idx);
    ret = min(ret, go(a, idx + 1));
    return ret;
}
int main() {
    fastio;
    cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < k; i++) {
        int t; cin >> t;
        vector<int> tmp(t);
        for(int j = 0; j < t; j++) {
            cin >> tmp[j];
        }
        sw.push_back(tmp);
    }
    int ans = go(a, 0);
    if(ans >= 100) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
    return 0;
}