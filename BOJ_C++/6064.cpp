#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}
int main() {
    fastio;
    int tc;
    cin >> tc;
    while(tc--) {
        int n, m;
        cin >> n >> m;
        int x, y;
        cin >> x >> y;
        int GCD = gcd(n, m);
        int LCM = n / GCD * m;        
        int ans = -1;
        for(int i = x - 1; i <= LCM; i += n) {
            if(i % m == y - 1){
                ans = i + 1;
                break;
            }
        }
        cout << ans << '\n';
    }
      
    return 0;
}