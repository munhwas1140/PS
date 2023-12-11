#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n;
    while(cin >> n) {
        
        int ans = 1;
        int now = 1;
        while(1) {
            if(now % n == 0) {
                cout << ans << '\n';
                break;
            } else {
                now = (now * 10) + 1;
                now %= n;
                ans += 1;
            }
        }
    }

    return 0;
}