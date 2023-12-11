#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    vector<int> a(5);
    int sum = 0;
    for(int i = 0; i < 5; i++) {
        cin >> a[i];
        sum += a[i];
    }

    cout << sum / 5 << '\n';
    sort(a.begin(), a.end());
    cout << a[2] << '\n';

    return 0;
}