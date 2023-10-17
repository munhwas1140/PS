#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;

int n;
int dist[20][20];
bool unused[20][20];
int main() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(dist[i][k] == 0 || dist[k][j] == 0 || dist[i][j] == 0) continue;
                if(dist[i][j] == dist[i][k] + dist[k][j]) {
                    unused[i][j] = true;
                } else if(dist[i][j] > dist[i][k] + dist[k][j]) {
                    return !(cout << -1 << '\n');
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!unused[i][j]) ans += dist[i][j];
        }
    }
    cout << ans / 2 << '\n';

    return 0;
}