#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
bool chk[500];
bool go(int now) {
    memset(chk,false,sizeof(chk));
    while(1) {
        int sum = 0;
        while(now) {
            sum += (now % 10) * (now % 10);
            now /= 10;
        }
        if(sum == 1) return true;
        if(chk[sum]) return false;
        chk[sum] = true;
        now = sum;
    }
}
int main() {
    fastio;
    int n; cin >> n;
    vector<bool> check(n + 1, true);
    vector<int> prime;
    check[0] = check[1] = true;
    for(int i = 2; i <= n; i++) {
        if(check[i]) {
            prime.push_back(i);
            for(int j = i + i; j <= n; j += i) {
                check[j] = false;
            }
        }
    }

    vector<int> ans;
    for(int &p : prime) {
        if(go(p)) {
            ans.push_back(p);
        }
    }
    
    for(int &x : ans) {
        cout << x << '\n';
    }
      
    return 0;
}