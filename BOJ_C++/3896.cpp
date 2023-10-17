#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int main() {
    fastio;
    vector<bool> check(1299710, true);
    vector<int> prime;
    check[0] = check[1] = false;
    for(int i = 2; i <= 1299709; i++) {
        if(check[i]) {
            prime.push_back(i);
            for(int j = i + i; j <= 1299709; j += i) {
                check[j] = false;
            }
        }
    }

    int tc;
    cin >> tc;
    while(tc--) {
        int tmp; cin >> tmp;
        auto lb = lower_bound(prime.begin(), prime.end(), tmp);
        if(check[tmp]) cout << 0 << '\n';
        else cout << *lb - *(--lb) << '\n';
    }     
      
    return 0;
}