#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MAX = 10000000 + 1;
int minFactor[MAX], minFactorPow[MAX];
int factors[MAX];

void getFactorsSmart() {
    factors[1] = 1;
    for(int i = 2; i < MAX; i++) {
        if(minFactor[i] == i) {
            minFactorPow[i] = 1;
            factors[i] = 2;
        } else {
            int p = minFactor[i];
            int m = i / p;

            if(p != minFactor[m]) {
                minFactorPow[i] = 1;
            } else {
                minFactorPow[i] = minFactorPow[m] + 1;
            }

            int a = minFactorPow[i];
            factors[i] = (factors[m] / a) * (a + 1);
        }
    }
}

void solve() {
    int n, lo, hi;
    cin >> n >> lo >> hi;
    int ans = 0; 
    for(int i = lo; i <= hi; i++) {
        if(factors[i] == n) ans++;
    }
    cout << ans << '\n';
}
void init() {
    minFactor[0] = minFactor[1] = -1;
    for(int i = 2; i < MAX; i++) {
        minFactor[i] = i;
    }
    int sqrtMax = (int)(sqrt(MAX));
    for(int i = 2; i <= sqrtMax; i++) {
        if(minFactor[i] == i) {
            for(int j = i * i; j < MAX; j += i) {
                if(minFactor[j] == j) {
                    minFactor[j] = i;
                }
            }
        }
    }
}
int main() {
    fastio;
    int tc; cin >> tc;

    init();
    getFactorsSmart();
    while(tc--) {
        solve();
    }
    return 0;
}