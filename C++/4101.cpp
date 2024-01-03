#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    while(true) {
        int a, b;
        cin >> a >> b;
        if(a == 0 && b == 0) break;
        cout << (a > b ? "Yes" : "No") << '\n';
    }
    return 0;
}