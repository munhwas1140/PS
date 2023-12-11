#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int main() {
    fastio;
    vector<bool> check(123456 * 2 + 1, true);
    vector<int> prime;
    check[0] = check[1] = false;
    for(int i = 2; i <= 123456 * 2; i++) {
        if(check[i]) {
            prime.push_back(i);
            for(int j = i + i; j <= 123456 * 2; j += i) {
                check[j] = false;
            }
    }    
      
    while(1) {
        int tmp; cin >> tmp;
        if(!tmp) break;
        auto ub = upper_bound(prime.begin(), prime.end(), tmp * 2);
        auto lb = upper_bound(prime.begin(), prime.end(), tmp);
        cout << ub - lb << '\n';
    }
    return 0;
}