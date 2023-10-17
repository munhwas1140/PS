#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int now = 1;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] != now) {
            ans += 1;
        } else {
            now += 1;
        }
    }
    cout << ans << '\n';

     
    return 0;
}