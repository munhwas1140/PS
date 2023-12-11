#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    vector<vector<int>> a(5, vector<int>(5));
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<pii>> b(5, vector<pii>(5, make_pair(1, 25)));
    for(int i = 0; i < 5; i++) {
        int idx = -1;
        int v = -1;
        for(int j = 0; j < 5; j++) {
            if(a[i][j] != 0) {
                idx = j;
                v = a[i][j];
            }
            if(idx != -1) {
                for(int j = 0; j < idx; j++) {
                    b[i][j] = make_pair(1, v - 1);
                }
                for(int j = idx + 1; j < 5; j++) {
                    b[i][j] = make_pair(v + 1, 25);
                }
            }
        }

    }



    return 0;
}