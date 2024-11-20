#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int main() {
    fastio;
    double a[] = {13, 7, 5, 3, 3, 2};
    double t1 = 0, t2 = 1.5;
    for(int i = 0; i < 6; i++) {
        int x; cin >> x;
        t1 += x * a[i];
    }
    for(int i = 0; i < 6; i++) {
        int x; cin >> x;
        t2 += x * a[i];
    }
    if(t1 > t2) {
        cout << "cocjr0208" << '\n'; 
    } else {
        cout << "ekwoo" << '\n';
    }

    return 0;
}