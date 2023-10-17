#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int main() {
    fastio;
    int n, k;
    cin >> n >> k;
    vector<tuple<int,int,int>> aa(n);
    vector<int> a, b, c;
    for(auto &[x, y, z] : aa) {
        cin >> x >> y >> z;
        a.push_back(x);
        b.push_back(y);
        c.push_back(z);
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());
    int ans = 1e9;
    for(int &x : a) for(int &y : b) for(int &z : c) {
        int cnt = 0 ;
        for(auto &[t1, t2, t3] : aa) {
            if(x >= t1 && y >= t2 && z >= t3) cnt++;
            if(cnt >= k) {
                ans = min(ans, x + y + z);
            }
        }
    }
        
    

    cout << ans << '\n';

    return 0;
}