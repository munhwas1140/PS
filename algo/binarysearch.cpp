#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int BS(vector<int> &a, int s, int e, int k) {
    if(s == e) {
        if(a[s] == k) return s;
        else return -1;
    }
    int m = (s + e) / 2;
    if(k > a[m]) {
        return BS(a,m+1,e,k);
    } else if(k < a[m]) {
        return BS(a,s,m,k);
    } else {
        return m;
    }
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        cout << BS(a,0,n-1,k) << '\n';
    }

    return 0;
}