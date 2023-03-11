#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int x, n;
    cin >> x >> n;
    
    int sum = 0;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        sum += a * b;
    }

    if(sum == x) cout << "Yes" << '\n';
    else cout << "No" << '\n';
    return 0;
}