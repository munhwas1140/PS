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
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    
    sort(a.begin(), a.end());

    int tmp = 0;
    for(int i = 0; i < n / 2; i++) {
        tmp += a[i];
    }

    cout << tmp << ' ' << sum - tmp << '\n';

    return 0;
}