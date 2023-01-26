#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    vector<pii> a(n);
    vector<pii> tmp;
    for(auto &[s , e] : a) {
        cin >> s >> e;
        tmp.push_back({s, 1});
        tmp.push_back({e, -1});
    }


    sort(a.begin(), a.end());
    sort(tmp.begin(), tmp.end());
    

    int now = 0, pre = 0;
    int sum = 0;
    for(auto [x, v] : tmp) {
        if(now) sum += x - pre;
        now += v;
        pre = x;
    }

    int mn = 1e9;

    for(int i = 0; i < n; i++) {
        int ps = -1, pe = -1, ns = 1e9 + 1, ne = 1e9 + 1;
        if(i - 1 >= 0) {
            ps = a[i - 1].first;
            pe = a[i - 1].second;
        }
        if(i + 1 < n) {
            ns = a[i + 1].first;
            ne = a[i + 1].second;
        }

        int t = 0;
        if(pe >= ns) mn = 0;
        

        t += max(0, pe - a[i].first);
        t += max(0, a[i].second - ns);
        mn = min(mn, max(0, a[i].second - a[i].first - t));
    }
    cout << sum - mn << '\n';
    return 0;
}

// 1 4
// 3 7
// 5 9