#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int main() {
    fastio;
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }     
    
    ll ans = 0;
    while(pq.size() != 1) {
        ll t1, t2;
        t1 = pq.top();
        pq.pop();
        t2 = pq.top();
        pq.pop();
        ans += (t1 + t2);
        pq.push(t1 + t2);
    }
      
    cout << ans << '\n';
    return 0;
}