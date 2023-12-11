#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int main() {
    fastio;
    vector<bool> check(1001, true);
    check[0] = check[1] = false;
    for(int i = 2; i <= 1000; i++) {
        if(check[i]) {
            for(int j = i + i; j <= 1000; j += i) {
                check[j] = false;
            }
        }
    }

    int n;
    cin >> n;
    int ans = 0;
    while(n--) {
        int tmp;
        cin >> tmp;
        if(check[tmp]) ans += 1;
    }      
    cout << ans << '\n';
    return 0;
}