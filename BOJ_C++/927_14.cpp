#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    vector<int> a(n), ans(n);
    vector<int> check(1000001, -1);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        check[a[i]] = i;
    }

    sort(a.begin(), a.end());

    for(int i = 0; i < n; i++) {
        for(int j = a[i] * 2; j <= 1000000; j += a[i]) {
            if(check[j] != -1) {
                ans[check[j]]--;
                ans[check[a[i]]]++;
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}