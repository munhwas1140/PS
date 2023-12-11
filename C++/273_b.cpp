#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    ll a, b;
    cin >> a >> b;
    
    for(int i = 1; i <= b; i++) {
        ll tmp = pow(10, i);
        ll remain = a % tmp;
        if(remain >= tmp / 2) {
            a += tmp - remain;
        } else {
            a -= remain;
        }
    }
    cout << a << '\n';

    return 0;
}