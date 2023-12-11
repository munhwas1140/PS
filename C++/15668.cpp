#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
int n;
bool check[10];
int ans = -1;
bool ff(int a, int b) {
    memset(check,false,sizeof(check));
    while(a) {
        if(check[a%10]) return false;
        check[a%10] = true; a /= 10;
    }
    while(b) {
        if(check[b%10]) return false;
        check[b%10] = true; b /= 10;
    }
    return true;
}

int main() {
    fastio;
    cin >> n;
        
    for(int i = 1; i <= min(n / 2, 98765); i++) {
        if(ff(n - i, i)) return !(cout << i << " + " << n - i << '\n');
    }
    cout << -1 << '\n';
    return 0;
}