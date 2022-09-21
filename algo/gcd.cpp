#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}
int main() {
    fastio;
    int tc; cin >> tc; 
    while(tc--) {
        int a, b;
        cin >> a >> b;
        cout << gcd(a, b) << '\n';
    }
    return 0;
}