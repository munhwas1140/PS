#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int main() {
    fastio;
    vector<bool> check(1000001, true);
    vector<ll> prime;
    check[0] = check[1] = true;
    for(ll i = 2; i <= 1000000; i++) {
        if(check[i]) {
            prime.push_back(i * i);
            for(ll j = i; j <= 1000000; j += i) check[j] = false;
        }
    }
    cout << prime.size() << '\n';
    ll a, b;
    cin >> a >> b;
         
      
    return 0;
}