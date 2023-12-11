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
    int sum = a[n - 1] + a[n - 2];
    int mn = min(a[n - 1], a[n - 2]);
    double av = (sum - mn);
    vector<int> ans;
    ans.push_back(n - 2);
    for(int i = n - 3; i >= 1; i--) {
        sum += a[i];
        mn = min(mn, a[i]);
        double tmp = (sum - mn) / double(n - i - 1);
        if(abs(av - tmp) < 0.000001) {
            ans.push_back(i);
        } else if(av < tmp) {
            av = tmp;
            ans.clear();
            ans.push_back(i);
        }
    }

    sort(ans.begin(), ans.end());
    for(int x : ans) {
        cout << x << '\n';
    }

    return 0;
}