#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void addTo(vector<int> &a, vector<int> &b, int k) {
    a.resize(max(a.size(), b.size() + k));
    for(int i = 0; i < b.size(); i++) {
        a[i + k] += b[i];
    }
}
void subFrom(vector<int> &a, vector<int> &b) {
    a.resize(max(a.size(), b.size() + 1));
    for(int i = 0; i < b.size(); i++) {
        a[i] -= b[i];
    }
} 
vector<int> multiply(const vector<int> &a, const vector<int> &b) {
    vector<int> c(a.size() + b.size() + 1, 0);
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < b.size(); j++) {
            c[i + j] += a[i] * b[j];
        }
    }
    return c;
}
vector<int> karatsuba(vector<int> &a, vector<int> &b) {
    int an = a.size();
    int bn = b.size();
    if(an < bn) return karatsuba(b, a);

    if(an == 0 || bn  == 0) return vector<int>();

    if(an <= 50) return multiply(a, b);
    
    int half = an / 2;

    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());
    vector<int> b0(b.begin(), b.begin() + min(bn, half));
    vector<int> b1(b.begin() + min(bn, half), b.end());
    
    vector<int> z2 = karatsuba(a1, b1);
    vector<int> z0 = karatsuba(a0, b0);

    addTo(a0,a1,0);
    addTo(b0,b1,0);
    
    vector<int> z1 = karatsuba(a0, b0);
    subFrom(z1, z0);
    subFrom(z1, z2);

    vector<int> ret;
    addTo(ret, z0, 0);
    addTo(ret, z1, half);
    addTo(ret, z2, half * 2);

    return ret;

}
void solve() {
    string t1, t2;
    cin >> t1 >> t2;
    int n = t1.size(), m = t2.size();
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) a[i] = (t1[i] == 'M');
    for(int i = 0; i < m; i++) b[m - i - 1] = (t2[i] == 'M');
    vector<int> c = karatsuba(a, b);
    int ans = 0;
    for(int i = n - 1; i < m; i++) {
        if(!c[i]) ans++;
    }
    cout << ans << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}