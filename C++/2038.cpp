#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;

int main() {
    fastio;
    
    int n;
    cin >> n;
    if(n == 1) return !(cout << 1 << '\n');
    if(n == 2) return !(cout << 2 << '\n'); 
    vector<pair<ll, ll>> a;
    a.push_back({1, 1});
    a.push_back({2, 2});
    int idx = 1;
    ll l = 1, r = 2;
    ll prev;
    while(r <= n) {
        // cout << "l = " << l << " r = " << r << '\n';
        // for(int i = 0; i < a.size(); i++) {
        //     cout << a[i].first << " " << a[i].second << '\n';
        // }
        // cout << '\n';
        l++;
        if(a[idx].first == l) {
            prev = a[idx].second;
            idx++;
        }
        r += prev; 
        a.push_back({r,l + 1});
    }
    cout << l << '\n';
    return 0;
}