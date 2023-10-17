#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    deque<int> dq;
    for(int i = 0; i < n; i++) {
        dq.push_back(i + 1);
    }
    
    int ans = 0;
    for(int i = 0, tmp; i < k; i++) {
        cin >> tmp;
        for(int j = 0; j < dq.size(); j++) {
            if(dq[j] == tmp) {
                ans += min(j, (int)dq.size() - j);
                for(int k = 0; k < j; k++) {
                    dq.push_back(dq.front());
                    dq.pop_front();
                }      
                dq.pop_front();  
                break;
            }
        } 
    }
    cout << ans << '\n';
    return 0;
}