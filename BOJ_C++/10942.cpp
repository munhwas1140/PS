#include <bits/stdc++.h>
using namespace std;

int pel[2000][2000];
int a[2000];

int go(int x, int y) {
    if(x == y) return 1;
    
    int &ans = pel[x][y];
    if(ans != -1) return ans;
    if(x + 1 == y) {
        if(a[x] == a[y]) return ans = 1;
        return ans = 0;
    }

    if(a[x] != a[y]) return ans = 0;
    return ans = go(x + 1, y - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    memset(pel, -1, sizeof(pel));
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int q;
    cin >> q;
    while(q--) {
        int x, y;
        cin >> x >> y;
        cout << go(x - 1, y - 1) << '\n';
    }
    return 0;
}