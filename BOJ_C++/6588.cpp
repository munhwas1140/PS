#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int main() {
    fastio;
    vector<bool> check(1000001, true);
    vector<int> prime;
    check[0] = check[1] = false;
    for(int i = 2; i <= 1000000; i++) {
        if(check[i]) {
            prime.push_back(i);
            for(int j = i + i; j <= 1000000; j += i) {
                check[j] = false;
            }
        }
    }

    while(1) {
        int tmp; cin >> tmp;
        if(!tmp) break;

        bool ok = false;
        for(int i = 0; i < prime.size(); i++) {
            if(prime[i] > tmp / 2) break;
            if(check[tmp - prime[i]]) {
                ok = true;
                cout << tmp << " = " << prime[i] << " + " << tmp - prime[i] << '\n';
                break;  
            }
        }
        if(!ok) cout << "Goldbach's conjecture is wrong." << '\n';
    }
      
    return 0;
}