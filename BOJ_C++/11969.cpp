#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int psum[100001][4];
int main() {
    fastio;
    int n, q;
    cin >> n >> q;
    for(int i = 0, tmp; i < n; i++) {
        cin >> tmp;
        for(int j = 1; j <= 3; j++) {
            psum[i+1][j] = psum[i][j];
        }
        psum[i+1][tmp] += 1;
    }

    while(q--) {
        int t1, t2;
        cin >> t1 >> t2;
        for(int i = 1; i <= 3; i++) {
            cout << psum[t2][i] - psum[t1-1][i] << ' ';
        }
        cout << '\n';
    } 
    return 0;
}