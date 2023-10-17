#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;


int main() {
    fastio;
    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if(a > b) cout << a << '\n';
    else cout << b << '\n';     
      
    return 0;
}