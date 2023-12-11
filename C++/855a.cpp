#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    cout << "int a;\n";
    cout << "int *ptr = &a;\n";
    for(int i = 2; i <= n; i++) {
        cout << "int ";
        for(int j = 0; j < i; j++) {
            cout << "*";
        }
        cout << "ptr" << i << " = &ptr";
        if(i - 1 > 1) {
            cout << i - 1;
        }
        cout << ";\n";
    }
    return 0;
}