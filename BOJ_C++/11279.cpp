#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int main() {
    fastio;
    int n; cin >> n;
    priority_queue<int> pq;
    while(n--) {
        int tmp; cin >> tmp;
        if(tmp) pq.push(tmp);
        else {
            if(pq.empty()) cout << 0 << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }     
      
    return 0;
}