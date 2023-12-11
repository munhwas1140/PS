#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    vector<bool> a(2000003), b(2000003);

    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        a[tmp] = true;
    }

    for(int i = 1; i <= 2000003; i++) {
        if(a[i]) {
            for(int j = 1; j <= 2000003 / i; j++) {
                if(a[j]) b[i * j] = true;
            }
        }
    }

    if(!a[0]) return !(cout << 0 << '\n');

    for(int i = 1; i <= 2000003; i++) {
        if(!b[i]) return !(cout << i << '\n');
    }



    return 0;
}