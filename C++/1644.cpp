#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
int n;
int main() {
    fastio;
    vector<bool> check(4000001, true);
    vector<int> prime;
    check[0] = check[1] = false;
    for(int i = 2; i <= 4000000; i++) {
        if(check[i]) {
            prime.push_back(i);
            for(int j = i + i; j <= 4000000; j += i) check[j] = false;
        }
    }

    cin >> n;     
    int ans = 0;
    int l = 0, r = 0;
    int sum = 0;
    while(true) {
        // cout << l << ' ' << r << ' ' << sum << '\n';
        if(sum < n) {
            if(r == prime.size()) break;
            sum += prime[r++];
        } else if(sum == n) {
            ans += 1;
            sum -= prime[l++];
        } else {
            sum -= prime[l++];
        }
    }
    cout << ans << '\n';
      
    return 0;
}