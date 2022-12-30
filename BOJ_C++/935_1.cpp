#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int main() {
    fastio;
    vector<int> check(100001, false);
    vector<int> prime;
    for(int i = 2; i <= 100000; i++) {
        if(!check[i]) {
            prime.push_back(i);
            for(int j = i; j <= 100000; j += i) {
                check[j] = true;
            }
        }
    }

    int n; cin >> n;
    for(int i = 0; i < prime.size() - 1; i++) {
        int tmp = prime[i] * prime[i + 1];
        if(tmp > n) {
            return !(cout << tmp << '\n');
        }
    }
    
    return 0;
}