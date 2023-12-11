// #include <bits/stdc++.h>
// using namespace std;
// #define fastio cin.tie(0)->sync_with_stdio(0)
// using ll = long long;
// using pii = pair<int, int>;
// using pll = pair<ll, ll>;
// int main() {
//     fastio;
//     int n; cin >> n;
//     vector<ll> x1(n), x2(n), y1(n), y2(n), all_x(2 * n);
//     for(int i = 0; i < n; i++) {
//         cin >> x1[i] >> y2[i] >> x2[i] >> y1[i];
//         all_x[2 * i] = x1[i];
//         all_x[2 * i + 1] = x2[i];
//     }
//     sort(all_x.begin(), all_x.end());
    
//     ll ans = 0;

//     for(int i = 0; i < 2 * n; i++) {
//         ll x = all_x[i];
//         if(i && all_x[i] == all_x[i - 1]) continue;

//         vector<pll> pos;
//         for(int j = 0; j < n; j++) {
//             if(x1[j] <= x && x2[j] > x) {
//                 pos.push_back({y1[j], 1});
//                 pos.push_back({y2[j], -1});
//             }
//         }

//         if(pos.empty()) {
//             continue;
//         }

//         sort(pos.begin(), pos.end());
//         int it = 0;
//         ll total = 0;
//         while(it < pos.size()) {
//             int now = 1;
//             ll bottom = pos[it].first;
//             while(now) {
//                 now += pos[++it].second;
//             }
//             total += pos[it].first - bottom;
//             it++;
//         }
        
//         it = i;
//         while(all_x[i] == all_x[it]) it++;
//         ans += total * (all_x[it] - x);
//         i = it - 1;
//     }
//     cout << ans << '\n';
    

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
struct asdf {
    int x, y1, y2, d;
};
int main() {
    fastio;
    int n; cin >> n;
    vector<asdf> a;
    for(int i = 0; i < n; i++) {
        int x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);
        a.push_back({x1, y1, y2, 1});
        a.push_back({x2, y1, y2, 0});
    }
    sort(a.begin(), a.end(), [] (const asdf& u, const asdf &v) {
        return u.x < v.x;
    });

    ll ans = 0;
    int prex = 0;
    multiset<pii> ms;
    for(auto [x, y1, y2, d] : a) {
        int now = 0, sum = 0, prey = 0;
        for(auto [y, d] : ms) {
            if(now) sum += y - prey;
            now += d;
            prey = y;
        }
        ans += sum * (ll)(x - prex);
        if(d) {
            ms.insert({y1, 1});
            ms.insert({y2, -1});
        } else {
            ms.erase(ms.lower_bound({y1, 1}));
            ms.erase(ms.lower_bound({y2, -1}));
        }
        prex = x;
    }
    cout << ans << '\n';
    return 0;
}