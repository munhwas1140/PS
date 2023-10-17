#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
ll a[1000];
int cnt[1000];
int main() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<tuple<ll,int,int>> tpv;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            tpv.push_back({abs(a[i] - a[j]), i, j});
        }
    }
    sort(tpv.begin(), tpv.end());
    ll ans = 0;
    int tmp = 0;
    for(auto &[d, s, e] : tpv) {
        if(tmp == 2 * n) break;
        if(cnt[s] < 2 && cnt[e] < 2) {
            ans += d;
            cnt[s]++;
            cnt[e]++;
            tmp += 2;
        }
    }
    cout << ans << '\n';
    return 0;
} 