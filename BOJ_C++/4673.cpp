#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
int f(int now) {
    int tmp = 0;
    while(now) {
        tmp += now % 10;
        now /= 10;
    }
    return tmp;
}
int main() {
    fastio;
    vector<bool> check(10001);
    for(int i = 1; i <= 10000; i++) {
        int tmp = i + f(i);
        if(tmp <= 10000) check[tmp] = true;
    }     
    for(int i = 1; i <= 10000; i++) {
        if(!check[i]) cout << i << '\n';
    }
    return 0;
}