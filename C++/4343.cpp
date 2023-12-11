#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
int s, p;
int uf[500];
int find(int x) {
    if(uf[x] < 0) return x;
    return uf[x] = find(uf[x]);
}
void set_union(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return ;
    uf[x] = y;
}
double dist(pair<double, double> &a, pair<double, double> &b) {
    double t1 = (a.first - b.first) * (a.first - b.first);
    double t2 = (a.second - b.second) * (a.second - b.second);
    return sqrt(t1 + t2);
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        cin >> s >> p;
        vector<pair<double, double>> a(p);
        for(int i = 0; i < p; i++) {
            cin >> a[i].first >> a[i].second;
        }
        priority_queue<tuple<double, int, int>> pq;        
        for(int i = 0; i < p; i++) {
            for(int j = i + 1; j < p; j++) {
                pq.push({-dist(a[i], a[j]), i, j});
            }
        }
        
        int cnt = 0;
        double ans = 0;
        memset(uf,-1,sizeof(uf));
        while(cnt < p - s) {
            auto [d, x, y] = pq.top();
            pq.pop();
            d = -d;
            x = find(x);
            y = find(y);
            if(x != y) {
                if(cnt == p - s - 1) {
                    ans = d;
                    break;
                }
                cnt++;
                set_union(x, y);
            }
        }
        cout << fixed << setprecision(2);
        cout << ans << '\n';
    }

    return 0;
}