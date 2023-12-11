#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

pair<double, double> s, e;
int n;
double cost[102][102]; // 0 == s,  n + 1 == e
double dist[102];
vector<pair<double, double>> a;
double distCalc(pair<double, double> &a, pair<double, double> &b) {
    double t1 = (a.first - b.first) * (a.first - b.first);
    double t2 = (a.second - b.second) * (a.second - b.second);
    return sqrt(t1 + t2);
}

double calc(int i, int j) {
    pair<double, double> p1 = a[i], p2 = a[j];
    if(j == n) p2 = e;
    else if(j == -1) p2 = s;

    double tmp = distCalc(p1, p2); 
    if(tmp >= 50) {
        return 2.0 + (tmp - 50) / 5.0;
    } else {
        return min(tmp / 5.0, 2.0 + (50 - tmp) / 5.0);
    }
}

int main() {
    fastio;
    cin >> s.first >> s.second >> e.first >> e.second;
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
     

    for(int i = 0; i < n; i++) {
        cost[0][i + 1] = distCalc(s, a[i]) / 5.0;
    }
    cost[0][n + 1] = distCalc(s, e) / 5.0;
    
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            cost[j + 1][i + 1] = cost[i + 1][j + 1] = calc(i, j);
        }
        cost[i + 1][n + 1] = calc(i, n);
        cost[i + 1][0] = calc(i, -1);
    }

    for(int i = 0; i < n + 2; i++) dist[i] = 1e12;

    dist[0] = 0;
    priority_queue<pair<double, int>> pq;
    pq.push({0, 0});

    while(!pq.empty()) {
        auto [d, now] = pq.top();
        pq.pop();
        d = -d; 
        for(int i = 0; i < n; i++) {
            if(dist[i + 1] > d + cost[now][i + 1]) {
                dist[i + 1] = d + cost[now][i + 1];
                pq.push({-dist[i + 1], i + 1});
            }
        }
        if(dist[n + 1] > d + cost[now][n + 1]) {
            dist[n + 1] = d + cost[now][n + 1];
            pq.push({-dist[n + 1], n + 1});
        }
    } 

    cout << fixed << setprecision(6);
    cout << dist[n + 1] << '\n';
    return 0;
}