#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll MOD = 998244353;
ll f[101];
int d(const pii &x, const pii &y) {
    return abs(x.first - y.first) + abs(x.second - y.second);
}
int main() {
    f[0] = 1LL;
    for(int i = 1; i <= 100; i++) {
        f[i] = f[i - 1] * i;
        f[i] %= MOD;
    }
    fastio;
    int n; cin >> n;
    vector<pii> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    vector<vector<int>> dist(n, vector<int>(n, 0));
    map<int,vector<int>> mp;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            dist[i][j] = d(a[i], a[j]);
            if(!mp.count(dist[i][j])){
                mp[dist[i][j]].resize(n + 1);
            }
            mp[dist[i][j]][i]++;
            mp[dist[i][j]][j]++;
            mp[dist[i][j]][n] += 2;
        }
    }

    vector<int> pos;
    
    for(auto it = mp.begin(); it != mp.end(); it++) {
        vector<int> tmp = it->second;
        int sz = tmp[n] / 2;
        bool ok = true;
        int cnt = 0;
        vector<int> cand;
        vector<int> check(n);
        for(int i = 0; i < n; i++) {
            if(tmp[i]) {
                cnt++;
                check[i] = 1;
                cand.push_back(i);
                if(tmp[i] != sz - 1) {
                    ok = false;
                    break;
                }
            }
        }

        if(ok) {
            for(int x : cand) {
                for(int i = x + 1; i < n; i++) {
                    if(!check[i]) {
                        if(dist[x][i] < it->first) {
                            ok = false;
                        }
                    }
                }
            }
            if(!ok) continue;
            pos.push_back(cnt);
        }
    }


    function<ll(vector<int>,int, int)> go = [&] (const vector<int> &tmp, int idx, int now) {
        if(idx == tmp.size()) return f[now];
        ll ret = 0;

        ret += ((ll)now * go(tmp,idx + 1, now - tmp[idx] + 1)) % MOD;
        ret %= MOD;
        ret += go(tmp,idx + 1, now);
        ret %= MOD;
        return ret;
    };
    
    ll ans = go(pos,0, n);

    pos.clear();
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int now = dist[i][j];
            bool ok = true;
            for(int x = 0; x < n; x++) {
                if(x == i || x == j) continue;
                int next = dist[min(x, i)][max(x, i)];
                int next2 = dist[min(x, j)][max(x, j)];
                if(now <= next || now <= next2) ok = false;
            }
            

            if(ok) {
                pos.push_back(2);
            }
        }
    }

    ans += go(pos,0, n);
    ans %= MOD;
    ans -= f[n];
    ans += 2 * MOD;
    ans %= MOD;
    cout << ans << '\n';

    return 0;
}