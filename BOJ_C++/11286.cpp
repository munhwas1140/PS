#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int main() {
    fastio;
    int n; cin >> n;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    while(n--) {
        int tmp; cin >> tmp;
        if(tmp) pq.push({abs(tmp), (tmp > 0) ? 1 : -1});
        else {
            if(pq.empty()) cout << 0 << '\n';
            else {
                cout << pq.top().first * pq.top().second << '\n';
                pq.pop();
            }
        }
    }     
      
    return 0;
}