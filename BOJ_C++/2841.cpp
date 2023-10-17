#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, p;
    cin >> n >> p;
    stack<int> s[6];
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int t1,t2;
        cin >> t1 >> t2;
        
        while(!s[t1-1].empty() && s[t1-1].top() > t2) {
            ans += 1;
            s[t1-1].pop();
        }
        if(s[t1-1].empty() || s[t1-1].top() != t2) {
            s[t1-1].push(t2);
            ans += 1;
        }
    }    
    cout << ans << '\n';
      
    return 0;
}