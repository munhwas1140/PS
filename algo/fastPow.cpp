#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
int pow(int a, int b) {
    if(b == 0) return 1;
    else if(b % 2) {
        return (a * pow(a, b - 1)) % 1000;
    } else {
        int ret = pow(a, b / 2);
        return (ret * ret) % 1000;
    }
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        int a, b;
        cin >> a >> b;
        cout << pow(a, b) << '\n';
    }
    return 0;
}