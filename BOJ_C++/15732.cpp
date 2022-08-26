#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct asdf {
    int from, to, diff;
    asdf(int from, int to, int diff) : from(from), to(to), diff(diff) {}
    asdf() : from(0), to(0), diff(0) {}
};

int n, k, d;

ll check(vector<asdf> &a, int m) {
    ll ret = 0;
    
    for(auto &[from, to, diff] : a) {
        if(from <= m && m < to) {
            ret += (m - from) / diff + 1;
        } else if(to <= m) {
            ret += (to - from) / diff + 1;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k >> d;
    vector<asdf> a(k);

    for(auto &[from, to, diff] : a) {
        cin >> from >> to >> diff;
    } 

    int l = 1, r = n;
    int ans;
    while(l <= r) {
        int m = (l + r) / 2;
        ll c = check(a, m);
        // cout << "M = " << m << ' ' << c << '\n';

        if(c >= d) {
            ans = m;
            r = m - 1;
        } else l = m + 1;
    }
    cout << ans << '\n';
      
    return 0;
}