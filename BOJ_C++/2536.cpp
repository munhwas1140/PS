#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using Point = pll;
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

int n, m;
int stx, sty, edx, edy;
bool stline[5001], endline[5001];
int main() {
    fastio;
    cin >> n >> m;
    int k;
    cin >> k;
    vector<Line> a(k + 1);
    for(int i = 0; i < k; i++) {
        ll num, x1, y1, x2, y2;
        cin >> num >> x1 >> y1 >> x2 >> y2;
        if(x1 == x2) {
            if(y1 > y2) swap(y1, y2);
        }
        if(y1 == y2) {
            if(x1 > x2) swap(x1, x2);
        }
        a[num].first = make_pair(x1, y1);
        a[num].second = make_pair(x2, y2);
    }
    cin >> stx >> sty >> edx >> edy;

    vector<int> st;
    vector<vector<int>> g(k + 1, vector<int>());
    for(int i = 1; i <= k; i++) {
        if((a[i].first.first == a[i].second.first && a[i].first.first == stx && a[i].first.second <= sty && sty <= a[i].second.second)
            || (a[i].first.second == a[i].second.second && a[i].first.second == sty && a[i].first.first <= stx && stx <= a[i].second.first)) {
            st.push_back(i);
            stline[i] = true;
        }
        
        for(int j = i + 1; j <= k; j++) {
            if(cross(a[i], a[j])) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }

        if((a[i].first.first == a[i].second.first && a[i].first.first == edx && a[i].first.second <= edy && edy <= a[i].second.second)
            || (a[i].first.second == a[i].second.second && a[i].first.second == edy && a[i].first.first <= edx && edx <= a[i].second.first)) {
            endline[i] = true;
        }
    }

    queue<int> q;
    vector<int> dist(k + 1, -1);
    for(int x : st) {
        q.push(x);
        dist[x] = 1;
    }
    
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        if(endline[now]) {
            cout << dist[now] << '\n';
            break;
        }

        for(int &next : g[now]) {
            if(dist[next] == -1) {
                dist[next] = dist[now] + 1;
                q.push(next);
            }
        }
    }

    return 0;
}