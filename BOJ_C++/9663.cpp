#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int n;
vector<bool> col(15, false);
vector<bool> xdia(29, false);
vector<bool> ydia(14, false);
int go(int idx) {
    if(idx == n) {
        return 1;
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(!col[i] && !xdia[i - idx + 14] && !ydia[idx + i]) {
            col[i] = xdia[i - idx + 14] = ydia[idx + i] = true;
            cnt += go(idx + 1);
            col[i] = xdia[i - idx + 14] = ydia[idx + i] = false;
        }
    }
    return cnt;
}
int main() {
    fastio;
    cin >> n; 
    cout << go(0) << '\n';
    return 0;
}