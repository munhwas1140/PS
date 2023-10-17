#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    deque<pair<int,int>> dq;
    for(int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        dq.push_back(make_pair(tmp,i));
    }    

    while(dq.size() > 1) {
        auto p = dq.front();
        cout << p.second << ' ';
        dq.pop_front();
        if(p.first > 0) p.first--;
        while(p.first < 0) {
            p.first += dq.size();
        }
        for(int i = 0; i < p.first; i++) {
            dq.push_back(dq.front());
            dq.pop_front();
        }
        
    }
    cout << dq.front().second << '\n'; 
    return 0;
}