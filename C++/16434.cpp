#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll Hatk;
vector<tuple<int, ll, ll>> a;

bool check(ll mid) {
    ll curatk = Hatk;
    ll curHP = mid;

    for(int i = 0; i < n; i++) {
        int x; ll y, z;
        tie(x,y,z) = a[i];
        if(x == 1) {
            ll t1, t2;
            t1 = curHP / y + ((curHP % y) != 0);
            t2 = z / curatk + ((z % curatk) != 0);
            if(t2 <= t1) {
                curHP -= (t2 - 1) * y;
            } else return false;
        } else {
            curatk += y;
            curHP = min(mid, curHP + z);
        }
    }
    return true;

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> Hatk;
    a.resize(n);
    for(auto &[x,y,z] : a) cin >> x >> y >> z;
    ll l = 1, r = 123456e12;
    ll ans;
    while(l <= r) {
        ll mid = (l + r) / 2;
        if(check(mid)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    } 
    cout << ans << '\n';
    return 0;
}