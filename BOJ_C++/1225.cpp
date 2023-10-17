#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string a, b;
    cin >> a >> b;

    long long bv = 0;
    for(int i = 0; i < b.size(); i++) {
        bv += (b[i] - '0');
    }
    long long ans = 0;
    for(int i = 0; i < a.size(); i++) {
        ans += (a[i] - '0') * bv;
    }
    cout << ans << '\n';
    return 0;
}