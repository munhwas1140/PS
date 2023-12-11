#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    unsigned long long n; cin >> n;
    for(int i = 0; i < 65; i++) {
        if(n % 2) {
            cout << 64 - i << '\n';
            return 0;
        }
        n /= 2;
    }
    

    return 0;
}