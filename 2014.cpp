#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int main() {
    fastio;
    int k, n;
    cin >> k >> n;
    vector<ll> prime(k);
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for(int i = 0; i < k; i++) {
        cin >> prime[i];
        pq.push(prime[i]);
    }
      
    for(int i = 0; i < n - 1; i++) {
        ll now = pq.top();
        pq.pop();
    
        for(int j = 0; j < k; j++) {
            ll num = now * prime[j];
            if(num > INT_MAX) break;
            pq.push(num);
            if(now % prime[j] == 0) break;
        }
    }
    cout << pq.top() << '\n';
    return 0;
}