#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
int n;
int a[1500][1500];
int main() {
    fastio;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            pq.push(a[i][j]);
            if(pq.size() > n) {
                pq.pop();
            }
        }
    } 
    cout << pq.top() << '\n';
    
    return 0;
}