#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int psum[100001];
int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    for(int i = 0, tmp; i < n; i++) {
        cin >> tmp; 
        psum[i+1] = psum[i] + tmp;
    }

    while(m--) {
        int t1, t2;
        cin >> t1 >> t2;
        cout << psum[t2] - psum[t1 - 1] << '\n';
    }
      
    return 0;
}