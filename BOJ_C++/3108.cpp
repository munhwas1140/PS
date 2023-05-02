#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

using Point = pii;
using Line = pair<Point,Point>;
int ccw(Point p1, Point p2, Point p3) {
    long long tmp = p1.first*p2.second+p2.first*p3.second+p3.first*p1.second;
    tmp -= p1.second*p2.first+p2.second*p3.first+p3.second*p1.first;
    if(tmp < 0) return -1;
    else if(tmp > 0) return 1;
    else return 0;
}
bool cross(Line l1, Line l2) {
    int l1l2 = ccw(l1.first,l1.second,l2.first) * ccw(l1.first,l1.second,l2.second);
    int l2l1 = ccw(l2.first,l2.second,l1.first) * ccw(l2.first,l2.second,l1.second);
    
    if(l1l2 == 0 && l2l1 == 0) {
        if(l1.first > l1.second) {
            swap(l1.first,l1.second);
        }
        if(l2.first > l2.second) {
            swap(l2.first,l2.second);
        }
        return l2.first <= l1.second && l1.first <= l2.second;
    }
    return l1l2 <= 0 && l2l1 <= 0;
}

int par[1000];
int Find(int x) {
    if(par[x] < 0) return x;
    return par[x] = Find(par[x]);
}
void set_union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if(x != y) {
        par[x] = y;
    }
}

bool check(const Line &l) {
    // cout << l.first.first << ' ' << l.first.second << ' ' << l.second.first << ' ' << l.second.second << '\n';
    if(l.first.first == 0 && l.second.first == 0 && l.first.second * l.second.second < 0) return true;
    if(l.first.second == 0 && l.second.second == 0 && l.first.first * l.second.first < 0) return true;
    if(l.first.first == 0 && l.first.second == 0) return true;
    if(l.second.first == 0 && l.second.second == 0) return true;
    return false;
}

int main() {
    fastio;
    memset(par,-1,sizeof(par));

    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(4));
    vector<vector<Line>> l(n, vector<Line>(4));

    bool flag = false;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 4; j++) {
            cin >> a[i][j];
        }

        Point p1 = {a[i][0], a[i][1]};
        Point p2 = {a[i][2], a[i][3]};
        Point p3 = {a[i][0], a[i][3]};
        Point p4 = {a[i][2], a[i][1]};

        l[i][0] = {p1, p3};
        l[i][1] = {p3, p2};
        l[i][2] = {p1, p4};
        l[i][3] = {p4, p2};
        
    }
    
    for(int i = 0; i < n; i++) {
        for(int k = 0; k < 4; k++) {
            if(!flag && check(l[i][k])) {
                flag = true;
            }
        }
    
        for(int j = i + 1; j < n; j++) {
            for(int x = 0; x < 4; x++) {
                for(int y = 0; y < 4; y++) {
                    if(cross(l[i][x], l[j][y])) {
                        set_union(i, j);
                        break;
                    }
                }
            }
        }
    }

    set<int> st;
    for(int i = 0; i < n; i++) {
        st.insert(Find(i));
    }
    cout << (int)st.size() - flag << '\n';

    return 0;
}