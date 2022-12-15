#include <iostream>
#include <algorithm>
using namespace std;
int a[] = {1, 5, 10, 50, 100, 500, 1000};
void solve() {
    int n; cin >> n;
    int ans = 0;
    for(int i = 6; i >= 0; i--) {
        ans += n / a[i];
        n %= a[i];
    }
    cout << ans << '\n';
}
int main() {
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}