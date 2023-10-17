#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int l, n;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int change(char c) {
    if(c == 'R') return 1;
    return -1;
}

bool check(pii &p1, pii &p2, pii &now1, pii &now2) {
    if(now1.first == now2.first) {
        if(p1.first == p2.first) {
            if(p1.first != now1.first) return true;
            else {

            }
        } 
    } else if(now1.second == now2.second) {
        if(p1.second == p2.second) {
            if(p1.second != now1.second) return true;
            else {

            }
        }

    } else {

    }
}
int main() {
    fastio;
    cin >> l >> n;
    vector<pair<ll, char>> a(n);
    for(auto &[t, d] : a) {
        cin >> t >> d;
    }

    ll ans = 0;
    int x, y, dir;
    x = y = dir = 0;
    vector<pii> pos;
    pos.push_back({0, 0});
    for(auto [t, d] : a) {
        int nx = (x + dx[dir]) * t;
        int ny = (y + dy[dir]) * t;
        int ndir = (dir + change(d) + 4) % 4;
        
        auto now1 = make_pair(x, y);
        auto now2 = make_pair(nx, ny);

        for(int j = 0; j < pos.size() - 3; j++) {
            auto p1 = pos[j];
            auto p2 = pos[j + 1];
            if(!check(p1, p2, now1, now2)) {

            }
        }
        pos.push_back({nx, ny});

    }


    return 0;
}