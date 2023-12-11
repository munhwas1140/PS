#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;


int main() {
    fastio;
    string s;
    cin >> s;
    cout << fixed << setprecision(1);
    double ans;
    if(s[0] == 'A') {
        ans = 4.0;
        if(s[1] == '+') ans += 0.3;
        if(s[1] == '-') ans -= 0.3;
    } else if(s[0] == 'B') {
        ans = 3.0;
        if(s[1] == '+') ans += 0.3;
        if(s[1] == '-') ans -= 0.3;
    } else if(s[0] == 'C') {
        ans = 2.0;
        if(s[1] == '+') ans += 0.3;
        if(s[1] == '-') ans -= 0.3;
    } else if(s[0] == 'D') {
        ans = 1.0;
        if(s[1] == '+') ans += 0.3;
        if(s[1] == '-') ans -= 0.3;
    } else ans = 0.0;
    cout << ans << '\n';
      
    return 0;
}