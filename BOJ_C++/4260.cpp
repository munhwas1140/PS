#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

void go(vector<int> &pre, vector<int> &in, int l, int r, int pl, int pr) {
    if(l == r) {
        cout << in[l] << ' ';
        return ;
    } 
    for(int i = l; i <= r; i++) {
        if(in[i] == pre[pl]) {
            go(pre, in, l, i - 1, pl + 1, pl + i - l);
            go(pre, in, i + 1, r, pl + i - l + 1, pr);
            cout << in[i] << ' ';
        }
    }
}
int main() {
    fastio;
    int tc;
    cin >> tc;
    while(tc--) {
        int n;
        cin >> n;
        vector<int> pre(n), in(n);
        for(int i = 0; i < n; i++) {
            cin >> pre[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> in[i];
        }
    
        go(pre, in, 0, n - 1, 0, n - 1);
        cout << '\n';

    }
      
    return 0;
}