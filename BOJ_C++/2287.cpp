#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int main() {
    fastio;
    int k, n;
    cin >> k >> n;
    set<int> s[9];
    int st = k;        
    for(int i = 1; i < 9; i++) {
        s[i].insert(st);
        st = st * 10 + k;
    }

    for(int i = 1; i < 9; i++) {
        for(int j = 1; j < i; j++) {
            for(int a : s[j]) {
                for(int b : s[i - j]) {
                    s[i].insert(a+b);
                    if(a - b) s[i].insert(abs(a - b));
                    s[i].insert(a*b);
                    if(a > b) s[i].insert(a / b);
                    else s[i].insert(b / a);
                }
            }
        }
    }


    while(n--) {
        int tar; cin >> tar;
        bool ok = false;
        for(int i = 1; i < 9; i++) {
            if(s[i].find(tar) != s[i].end()) {
                cout << i << '\n';
                ok = true;
                break;
            }
        }
        if(!ok) cout << "NO" << '\n';
    }
    return 0;
}