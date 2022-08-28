#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;


int main() {
    fastio;
    int tc;
    cin >> tc;
    while(tc--) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << min({a, b, c}) << '\n';
    }        
    return 0;
}