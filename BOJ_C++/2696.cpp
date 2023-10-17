#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int main() {
    fastio;
    int tc;
    cin >> tc;
    while(tc--) {
        int n;
        cin >> n;
        priority_queue<int> l;
        priority_queue<int,vector<int>, greater<int>> r;
        vector<int> ans;
        for(int i = 1, tmp; i <= n; i++) {
            cin >> tmp;
            if(l.empty()) {
                l.push(tmp);
            } else {
                if(l.top() > tmp) {
                    l.push(tmp);
                } else {
                    r.push(tmp);
                }
            }
            
            if(l.size() == r.size() + 2) {
                r.push(l.top()); l.pop();
            } else if(r.size() == l.size() + 1) {
                l.push(r.top()); r.pop();
            }
            if(i % 2) ans.push_back(l.top());
        }
    
        int sz = ans.size();
        cout << sz;
        for(int i = 0; i < sz; i++) {
            if(i % 10 == 0) cout << '\n';
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }     
      
    return 0;
}