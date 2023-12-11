#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> dist(n - 1);
    vector<long long> cost(n);
    for(int i = 0; i < n - 1; i++) {
        cin >> dist[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    long long ans = 0;
    int tmpDist = 0;
    int cur = 0;
    for(int i = 0; i < n - 1; i++) {
        if(cost[i] < cost[cur]) {
            ans += tmpDist * cost[cur];
            cur = i;
            tmpDist = dist[i];
        } else {
            tmpDist += dist[i];
        }
        
    }
    ans += tmpDist * cost[cur];
    cout << ans << '\n';

    return 0;
}