#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    map<string, int> M;
    vector<string> a(n + 1);
    for(int i = 0; i < n; i++) {
        string tmp;

        cin >> tmp;
        M[tmp] = i + 1;
        a[i + 1] = tmp;
    }  

    while(m--) {
        string tmp;
        cin >> tmp;
        if('0' <= tmp[0] && tmp[0] <= '9') {
            int x = stoi(tmp);
            cout << a[x] << '\n';
        } else {
            cout << M[tmp] << '\n';
        }
    }
    return 0;
}