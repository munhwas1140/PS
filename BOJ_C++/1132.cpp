#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
ll cnt[26];
ll allo[26];
bool ok[26];
int main() {
    fastio;
    int n; cin >> n;
    vector<string> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        ll tmp = 1LL;
        for(int j = a[i].size() - 1; j >= 0; j--) {
            if(j == 0) ok[a[i][j] - 'A'] = true;
            cnt[a[i][j] - 'A'] += tmp;
            tmp *= 10LL;
        }
    }

    vector<pll> v;
    for(int i = 0; i < 26; i++) {
        if(cnt[i]) v.push_back({cnt[i], i});
    }

    sort(v.begin(), v.end());
    memset(allo,-1,sizeof(allo));
    if(v.size() == 10) {
        for(int i = 0; i < v.size(); i++) {
            if(ok[v[i].second] == false) {
                allo[v[i].second] = 0;
                break;
            }
        }
    }

    ll now = 9;
    for(int i = v.size() - 1; i >= 0; i--) {
        if(allo[v[i].second] == 0) continue;
        allo[v[i].second] = now--;
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ll tmp = 0;
        for(char &x : a[i]) {
            tmp *= 10;
            tmp += allo[x - 'A'];
        }
        ans += tmp;
    }
    
    cout << ans << '\n';

    return 0;
}