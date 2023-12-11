#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int a[10][10];
int b[12][12];
int dist[120][120];
priority_queue<int> pq[120];
void init() {
    for(int i = 0; i < 120; i++) {
        for(int j = 0; j < 120; j++) {
            dist[i][j] = a[i / 12][j / 12] + b[i % 12][j % 12];
        }
    }
}
int main() {
    fastio;
    int n; cin >> n;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < 12; i++) {
        for(int j = 0; j < 12; j++) {
            cin >> b[i][j];
        }
    }

    init();

    for(int i = 0; i < n; i++) {
        int cost; string str;
        cin >> cost >> str;
        int idx = (str[0] - '0') * 12 + (str[1] - 'A');
        pq[idx].push(cost);
    }

    int ans = -1;
    int cx, cy;
    for(int x = 0; x < 120; x++) {
        if(pq[x].empty()) continue;
        cx = pq[x].top(); pq[x].pop();
        for(int y = x; y < 120; y++) {
            if(pq[y].empty()) continue;
            cy = pq[y].top(); pq[y].pop();
            for(int z = y; z < 120; z++) {
                if(pq[z].size()) ans = max(ans, dist[x][y] + dist[y][z] + dist[x][z] + cx + cy + pq[z].top());
            }
            pq[y].push(cy);
        }
        pq[x].push(cx);
    }
    cout << ans << '\n';

    return 0;
}