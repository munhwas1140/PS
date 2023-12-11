#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    ans = n / 5;
    if(n % 5 % 2 == 0) {
        ans += (n % 5) / 2;
    } else if(ans >= 1 && (n % 5 + 5) % 2 == 0) {
        ans += (n% 5 + 5) / 2;
        ans -= 1;
    } else if(ans >= 2 && (n % 5 + 10) % 2 == 0) {
        ans += (n % 5 + 10) / 2;
        ans -= 2;
    } else {
        ans = -1;
    }
    cout << ans << '\n';

    return 0;
}