#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;


int main() {
    fastio;
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }    
    vector<int> diff(n - 1);
    for(int i = 0; i < n - 1; i++) {
        diff[i] = abs(a[i+1] - a[i]);
    }
    
    vector<int> diffs(n);
    for(int i = 0; i < n - 1; i++) {
        diffs[i + 1] = diffs[i] + diff[i];
    }

    while(q--) {
        int t1, t2;
        cin >> t1 >> t2;
        t2--; t1--;
        if(t2 - 1 < t1) cout << 0 << '\n';
        else cout << diffs[t2] - diffs[t1] << '\n';
    }
    return 0;
}