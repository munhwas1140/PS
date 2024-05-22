#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
map<ll, int> mp;
int ans;
void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    mp.clear();
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]] += 1;
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    vector<vector<int>> g(a.size(), vector<int>())
    int sz = a.size();
    for(int i = 0; i < sz; i++) {
        for(int j = i + 1; j < sz; j++) {
            if(a[j] % a[i] == 0) g[i].push_back(j);
        }
    }
    ans = 0;
    for(int i = 0; i < n; i++) {
        memset(visited, false, sizeof(visited));
        go(i);
    }

        1 -> 1, 2, 3, 10, 20, 60
        2 -> 2, 10, 20, 60
        3 -> 3, 60
        10 -> 10, 20, 60
        20 -> 20, 60
        60 -> 60
    // 자기보다 크면서 없는거 연결
        1 ->
        2 -> 3
        3 -> 10, 20
        10 ->
        20 ->
        60 ->
    -----
        1 -> 1
        2 -> 1, 2
        3 -> 1, 3
        10 -> 1, 2, 10
        20 -> 1, 2, 10, 20
        60 -> 1, 2, 3, 10, 20, 60
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}
