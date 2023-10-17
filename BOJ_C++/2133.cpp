#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

ll d[31][1<<3];
int main() {
    fastio;
    int n;
    cin >> n;

    d[0][7] = 1;
    for(int i = 1; i <= n; i++) {
        d[i][0] = d[i-1][7];
        d[i][1] = d[i-1][6];
        d[i][3] = d[i-1][7] + d[i-1][4];
        d[i][4] = d[i-1][3];
        d[i][6] = d[i-1][7] + d[i-1][1];
        d[i][7] = d[i-1][0] + d[i-1][6] + d[i-1][3];
    }
    
    cout << d[n][7]; 
    return 0;
}