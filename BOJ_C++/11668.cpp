#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
typedef pair<int,int> Point;
struct Line {
    Point p1, p2;
    Line() {};
    Line(Point p1, Point p2) : p1(p1), p2(p2) {}
};

int w, p, SCCcnt;
vector<Point> sp;
vector<Line> edge;
vector<int> g[2020], gp[2020], order;
int SCC[2020];
bool visited[2020];
int ccw(Point u, Point v, Point w) {
    int t1 = (v.first - u.first) * (w.second - u.second);
    int t2 = (v.second - u.second) * (w.first - u.first);
    if(t1 - t2 > 0) return 1;
    else if(t1 - t2 < 0) return -1;
    return 0;
}
bool cross(Line u, Line v) {
    Point a = u.p1; Point b = u.p2;
    Point c = v.p1; Point d = v.p2;
    int asect = ccw(a, b, c) * ccw(a, b, d);
    int bsect = ccw(c, d, a) * ccw(c, d, b);
    if(!asect && !bsect) {
        if(a > b) swap(a, b);
        if(c > d) swap(c, d);
        return c <= b && a <= d;
    }
    return asect <= 0 && bsect <= 0;
}
void dfs(int now) {
    visited[now] = true;
    for(int &next : g[now]) {
        if(!visited[next]) dfs(next);
    }
    order.push_back(now);
}
void dfs_rev(int now, int num) {
    visited[now] = true;
    SCC[now] = num;
    for(int &next : gp[now]) {
        if(!visited[next]) dfs_rev(next, num);
    }
}
int main() {
    fastio;
    cin >> w >> p;
    for(int i = 0; i < w; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        sp.push_back({t1, t2});
    }
    for(int i = 0; i < p; i++) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        edge.push_back(Line(sp[t1 - 1], {t2, t3}));
    }

    for(int i = 0; i < p; i++) { 
        for(int j = i + 1; j < p; j++) {
            if(cross(edge[i], edge[j]) && edge[i].p1 != edge[j].p1) {
                // cout << "TRBUE  = " << i << ' ' << j << '\n';
                int t1 = i * 2;
                int t2 = j * 2;
                int nt1 = t1 + 1;
                int nt2 = t2 + 1;
                g[t1].push_back(nt2);
                g[t2].push_back(nt1);
                g[nt1].push_back(t2);
                g[nt2].push_back(t1);
                
                gp[t1].push_back(nt2);
                gp[t2].push_back(nt1);
                gp[nt1].push_back(t2);
                gp[nt2].push_back(t1);
            }
        }
    }
    for(int i = 0; i < 2 * p; i++) {
        if(!visited[i]) dfs(i);
    }

    memset(visited,false,sizeof(visited));
    reverse(order.begin(), order.end());

    for(int &i : order) {
        if(!SCC[i]) dfs_rev(i, ++SCCcnt);
    }

    bool ok = true;
    for(int i = 0; i < p; i++) {
        if(SCC[i * 2] == SCC[i * 2 + 1]) ok = false;
    }

    cout << (ok ? "possible" : "impossible") << '\n';
    return 0;
}