#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int go(vector<int> &a, int l, int r) {
    if(l == r) {
        return a[l];
    }
    
    int pivot = l;
    for(int i = l; i <= r; i++) {
        if(a[i] < a[pivot]) {
            pivot = i;
        }
    }

    int ans = a[pivot] * (r - l + 1);
    if(pivot - 1 >= l) {
        ans = max(ans, go(a, l, pivot - 1));
    }
    if(pivot + 1 <= r) {
        ans = max(ans, go(a, pivot + 1, r ));
    }
    return ans;
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << go(a,0, n - 1) << '\n';
    }

    return 0;
}