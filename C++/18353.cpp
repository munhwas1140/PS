#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    reverse(a.begin(), a.end());
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        auto it = lower_bound(ans.begin(), ans.end(), a[i]);
        if(it == ans.end()) ans.push_back(a[i]);
        else *it = a[i];
    }

    cout << n - (int)ans.size() << '\n';

    return 0;
}