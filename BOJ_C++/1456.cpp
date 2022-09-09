#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int main() {
    fastio;
    vector<int> check(10000001, true);
    vector<ll> prime;
    check[0] = check[1] = false;
    for(ll i = 2; i <= 10000000; i++) {
        if(check[i]) {
            for(ll j = i; j <= 10000000; j += i) {
                check[j] = false;
            }
            ll tmp = i * i;
            ll prev = tmp;            
            while(true) {
                bool ok = true;
                prime.push_back(tmp);

                for(int j = 0; j < i - 1; j++) {
                    tmp += prev;
                    if(tmp > 100000000000000) {
                        ok = false;
                        break;
                    }
                }
                if(!ok) break;
                prev = tmp;
            }
        }
    }
      
    sort(prime.begin(), prime.end());
    
    ll a, b;
    cin >> a >> b;
    auto t1 = lower_bound(prime.begin(), prime.end(), b);
    auto t2 = lower_bound(prime.begin(), prime.end(), a);
    ll ans = t1 - t2;
    if(*t1 == b) ans += 1; 
    cout << ans << '\n'; 
    return 0;
}