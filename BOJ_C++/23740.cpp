#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
int main() {
    fastio;
    cin >> n;
    vector<tuple<int,int,int>> a(n);
    for(auto &[from, to, cost] : a) {
        cin >> from >> to >> cost;
    }
    sort(a.begin(), a.end());
    vector<tuple<int,int,int>> ans;
    int ns = -1;
    int ne = -1;
    int nowcost = -1;
    for(auto [from, to, cost] : a) {
        if(ne < from) {
            if(ne != -1) {
                ans.push_back(make_tuple(ns, ne, nowcost));
            }
            ns = from;
            ne = to;
            nowcost = cost;
        } else {
            ne = max(ne, to);
            nowcost = min(nowcost, cost);
        }
    }
    ans.push_back(make_tuple(ns, ne, nowcost));


    cout << (int)ans.size() << '\n';
    for(auto [from, to, cost] : ans) {
        cout << from << ' ' << to << ' ' << cost << '\n';
    }

    return 0;
}