#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long; 
using ld = long double;
ld dist(pair<ld, ld> &a, pair<ld, ld> &b) {
    ld t1 = (a.first - b.first) * (a.first - b.first);
    ld t2 = (a.second - b.second) * (a.second - b.second);
    return sqrt(t1 + t2);
}
ld triangle(pair<ld, ld> &a, pair<ld, ld> &b, pair<ld, ld> &c) {
    ld t1 = a.first * b.second + b.first * c.second + c.first * a.second;
    ld t2 = b.first * a.second + c.first * b.second + a.first * c.second;
    return abs(t1 - t2) / 2.0;
}
ld inpro(pair<ld, ld> &a, pair<ld, ld> &b) {
    return a.first * b.first + a.second * b.second;
}
int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<vector<pair<ld, ld>>> a(n,vector<pair<ld, ld>>(2));
    vector<vector<pair<ld, ld>>> b(m,vector<pair<ld, ld>>(2));
      
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2; j++) {
            cin >> a[i][j].first >> a[i][j].second;
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < 2; j ++) {
            cin >> b[i][j].first >> b[i][j].second;
        }
    }
    
    ld ans = 1e12;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            auto line = make_pair(a[i][1].first - a[i][0].first, a[i][1].second - a[i][0].second);
            auto line2 = make_pair(b[j][1].first - b[j][0].first, b[j][1].second - b[j][0].second);
            ld d = dist(a[i][0], a[i][1]);
            ld d2 = dist(b[j][0], b[j][1]);
            for(int x = 0; x < 2; x++) {
                auto t1 = make_pair(b[j][x].first - a[i][0].first, b[j][x].second - a[i][0].second);
                auto t2 = make_pair(b[j][x].first - a[i][1].first, b[j][x].second - a[i][1].second);
                auto t3 = make_pair(a[i][x].first - b[j][0].first, a[i][x].second - b[j][0].second);
                auto t4 = make_pair(a[i][x].first - b[j][1].first, a[i][x].second - b[j][1].second);
                if(inpro(line,t1) * inpro(line,t2) < 0) {
                    ld tri = triangle(a[i][0],a[i][1],b[j][x]);
                    if(ans > (2 * tri / d)) {
                        ans = 2 * tri / d; 
                    }
                }
                if(inpro(line2,t3) * inpro(line2,t4) < 0) { 
                    ld tri = triangle(b[j][0],b[j][1],a[i][x]);
                    if(ans > (2 * tri / d2)) {
                        ans = 2 * tri / d2; 
                    }
                }
                for(int y = 0; y < 2; y++) {
                    ld tmp = dist(a[i][x],b[j][y]);
                    if(ans > tmp) ans = tmp;
                }
            }
        }
    }

    cout << fixed << setprecision(12);
    cout << ans << '\n';
    return 0;
}