#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
bool check[255];
int main() {
    string tmp = "CAMBRIDGE";
    for(char x : tmp) {
        check[x] = true;
    }

    fastio;
    string str;
    cin >> str;
    
    for(char x : str) {
        if(check[x]) continue;
        cout << x;
    }
    cout << '\n';

    return 0;
}