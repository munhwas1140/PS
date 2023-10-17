#include <bits/stdc++.h>
using namespace std;
long long fi[10001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    fi[0] = 0;
    fi[1] = 1;
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++) {
        fi[i] = fi[i-1] + fi[i-2];
    }
    cout << fi[n];

    return 0;
}