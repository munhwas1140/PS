#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int a[8];
int main() {
    fastio;
    int n, k;
    cin >> n >> k;
    uint start = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        start += a[i];
        if(i != n -1)start <<= 4;    
    }
    uint end = 0;
    for(int i = 1; i <= n; i++) {
        end += i;
        if(i != n) end <<= 4;
    }
    queue<uint> q;
    q.push(start);
    map<uint, int> m;    
    m[start] = 0;
    while(!q.empty()) {
        auto now = q.front();
        q.pop();
        if(now == end) break;
        int dist = m[now];
        vector<int> tmp(n);
        for(int i = n - 1; i >= 0; i--) {
            tmp[i] = now & 15;
            now >>= 4;
        }
        
        for(int i = 0; i <= n - k; i++) {
            vector<int> ttmp = tmp;
            reverse(ttmp.begin() + i, ttmp.begin() + i + k);
            uint state = 0;
            for(int i = 0; i < n; i++) {
                state += ttmp[i];
                if(i != n -1) state <<= 4;
            }
            if(m.count(state) == 0) {
                m[state] = dist + 1;
                q.push(state);
            }
        }
    }
    
    
    if(m.count(end) == 0) cout << -1 << '\n';
    else cout << m[end] << '\n';    
    return 0;
}