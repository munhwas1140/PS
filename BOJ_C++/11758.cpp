#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
int cross(int x1, int y1, int x2, int y2) {
    return x1 * y2 - x2 * y1;
}
int main() {
    fastio;
    int x1,y1,x2,y2,x3,y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int c = cross(x2-x1, y2-y1, x3-x2, y3-y2);
    if(c > 0) cout << 1 << '\n';
    else if(c < 0) cout << -1 << '\n';
    else cout << 0 << '\n'; 
      
    return 0;
}