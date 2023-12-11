#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;

int main() {
    fastio;
    int g;
    cin >> g;
    vector<int> a;
    for(int i = 1; i * i - (i - 1) * (i - 1) <= 100000; i++) {
        a.push_back(i);
    }
    
    int l = 0,  r = 0;
    
    bool ok = false;
    while(r < a.size()) {
        int tmp = a[r] * a[r] - a[l] * a[l];
        if(tmp < g) {
            r++;
        } else if(tmp == g) {
            ok = true;
            cout << a[r] << '\n';
            l++;
        } else {
            l++;
        }
    }
    if(!ok) cout << -1 << '\n';
      
    return 0;
}