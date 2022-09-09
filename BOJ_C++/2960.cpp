#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int main() {
    fastio;
    int n, k;
    cin >> n >> k;
    vector<bool> check(n + 1, true);
    check[0] = check[1] = false;
    
    for(int i = 2; i <= n; i++) {
        if(check[i]) {
            for(int j = i; j <= n; j += i) {
                if(check[j]) {
                    check[j] = false;
                    k--;
                    if(k == 0) {
                        return !(cout << j << '\n');
                    }
                }
            }
        }
    }

    return 0;
}