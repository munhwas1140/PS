#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n, k;
    cin >> n >> k;
    if(n < (k * (k + 1)) / 2) cout << -1 << '\n';
    else {
        int tmp = n - (k * (k + 1)) / 2;
        cout << (tmp % k == 0 ? k - 1 : k) << '\n';
        
    }
    return 0;
}