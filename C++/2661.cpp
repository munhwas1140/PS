#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int a[81];
int n;

bool check(int idx) {
    for(int i = 2; i <= idx / 2; i++) {
        for(int j = 0; j <= idx - i * 2; j++) {
            bool ok = true;
            for(int k = 0; k < i; k ++) {
                if(a[j + k] != a[j + i + k]) {
                    ok = false;
                    break;
                }
            }
            if(ok) return false;
        } 
    }
    return true;
}

void go(int idx) {
    if(idx == n) {
        for(int i = 0; i < n; i++) {
            cout << a[i];
        }
        exit(0);
    }

    for(int i = 1; i <= 3; i++) {
        if(idx > 0) if(a[idx-1] == i) continue;
        a[idx] = i;
        if(check(idx + 1)) go(idx + 1);
    }
    return ;
}
int main() {
    fastio;
    cin >> n;
    go(0);
    return 0;
}