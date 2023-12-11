#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n, g;
    cin >> n >> g;
    vector<tuple<int,int,int>> a(n);
    map<int,int> now, num;
    num[g] = 1e9;
    for(auto &[d, id, dif] : a) {
        cin >> d >> id >> dif;
        now[id] = g;
    }

    sort(a.begin(), a.end());

    int ans = 0;
    for(auto [d, id, diff] : a) {
        int cur = now[id];
        now[id] += diff;
        int next = now[id];

        auto it = num.end();
        it--;

        if(next > it->first) {
            if(cur < it->first || num[cur] > 1) ans++;
        } else if(next == it->first) {
            ans++;
        } else {
            if(cur == it->first) {
                it--;
                if(next <= it->first) ans++;
            }
        }

        num[cur]--;
        if(num[cur] == 0) {
            num.erase(num.find(cur));
        }
        num[next]++;
    }

    cout << ans << '\n';
    return 0;
}