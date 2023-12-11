#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;


int main() {
    fastio;
    int tc;
    cin >> tc;
    while(tc--) {
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int pSum1 = 0, pSum2 = 0, result = -1e9;
        for(int i = 0; i < n; i++) {
            pSum1 += a[i];
            result = max(pSum1 - pSum2, result);
            pSum2 = min(pSum2, pSum1);
        }
        cout << result << '\n';
    }
    return 0;
}