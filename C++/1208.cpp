#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int m = n / 2;
    n -= m;

    vector<int> l(1 << n);
    vector<int> r(1 << m);
    
    for(int i = 0; i < (1 << n); i++) {
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) l[i] += a[j];
        }
    }

    for(int i = 0; i < (1 << m); i++) {
        for(int j = 0; j < m; j++) {
            if(i & (1 << j)) r[i] += a[j + n];
        }
    }

    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    n = (1 << n);
    m = (1 << m);
    int lit = 0;
    int rit = m - 1;
    ll ans = 0;
    while(lit < n && rit >= 0) {
        int t1, t2;
        if(l[lit] + r[rit] == s) {
            ll t1, t2;
            t1 = t2 = 1;
            lit++;
            rit--;
            while(lit < n && (l[lit] == l[lit - 1])) {
                t1++;
                lit++;
            }
            while(rit >= 0 && (r[rit] == r[rit + 1])) {
                t2++;
                rit--;
            }
            ans += t1 * t2;
        } else if(l[lit] + r[rit] < s) {
            lit++;
        } else if(l[lit] + r[rit] > s) {
            rit--;
        } 
    }
    if(s == 0) ans--;
    cout << ans << '\n';
    return 0;
}