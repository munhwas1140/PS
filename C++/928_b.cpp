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
    cout << fixed << setprecision(6);
    if(n == 1) {
        cout << a[0] << '\n';
    } else {
        cout << max((double)a[n - 2], sum / (double)n) << '\n';

    }


    return 0;
}