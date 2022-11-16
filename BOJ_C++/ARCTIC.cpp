#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
double dist[101][101];
int n;
bool check(double val) {
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(int i = 0; i < n; i++) {
            if(i == now || visited[i]) continue;
            if(dist[now][i] <= val) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        if(!visited[i]) return false;
    }
    return true;
}
void solve() {
    cin >> n;
    vector<pair<double, double>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            double t1 = (a[i].first - a[j].first) * (a[i].first - a[j].first);
            double t2 = (a[i].second - a[j].second) * (a[i].second - a[j].second);
            dist[i][j] = dist[j][i] = sqrt(t1 + t2);
        }
    }

    double l = 0, r = 1500;
    double ans ;
    for(int i = 0; i < 100; i++) {
        double mid = (l + r) / 2.0;
        if(check(mid)) r = mid;
        else l = mid;
    }
    cout << fixed << setprecision(2);
    cout << l << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}