#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;


int psum[200001][26];
int main() {
    fastio;
    string str;
    cin >> str;     
    int n = str.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 26; j++) psum[i+1][j] = psum[i][j];
        psum[i+1][str[i] - 'a'] += 1;
    }

    int q;
    cin >> q;
    while(q--) {
        char op; int t1, t2;
        cin >> op >> t1 >> t2;
        cout << psum[t2+1][op - 'a'] - psum[t1][op - 'a'] << '\n';
    }
      
    return 0;
}