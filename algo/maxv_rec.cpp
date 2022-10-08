#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int recur_max(vector<int> &a, int s, int e) {
    if(s == e) {
        return a[s];
    } else {
        int mid = (s + e) / 2;
        return max(recur_max(a,s,mid), recur_max(a,mid + 1,e));
    }
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
        cout << recur_max(a,0, n - 1) << '\n';
    }

    return 0;
}