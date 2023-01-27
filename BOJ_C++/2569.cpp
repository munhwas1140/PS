#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    vector<pii> a(n + 1);
    vector<bool> visited(n + 1);
    int mn = 1e9;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
        mn = min(mn, a[i].first);
    }

    sort(a.begin() + 1, a.end());
    vector<vector<int>> pos;

    function<void(int,vector<int> &)> go = [&] (int now, vector<int> &tmp) {
        visited[now] = true;
        tmp.push_back(a[now].first);
        if(visited[a[now].second]) return;
        go(a[now].second, tmp);
    };

    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(!visited[i] && a[i].second != i) {
            vector<int> tmp;
            go(i,tmp);
            pos.push_back(tmp);
        }
    }

    ll ans = 0;
    for(auto &tmp : pos) {
        sort(tmp.begin(), tmp.end());
        ll sum = 0;
        for(int &x : tmp) {
            sum += (ll)x;
        }
        ll sum2 = sum;
        sum += (ll)tmp[0] * ((int)tmp.size() - 2);
        sum2 += (ll)mn * ((int)tmp.size() + 1) + (ll)tmp[0];
        ans += min(sum, sum2);
    }
    cout << ans << '\n';

    return 0;
}