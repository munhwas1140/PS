#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    while(tc--) {
        string str;
        cin >> str;
        deque<char> l, r;
        for(char &x : str) {
            if(x == '<') {
                if(!l.empty()) {
                    r.push_front(l.back());
                    l.pop_back();
                }
            } else if(x == '>') {
                if(!r.empty()) {
                    l.push_back(r.front());
                    r.pop_front();
                }
            } else if(x == '-') {
                if(!l.empty()) {
                    l.pop_back();
                }
            } else {
                l.push_back(x);
            }
        }
        for(char &x : l) cout << x;
        for(char &x : r) cout << x;
        cout << '\n';
    }     
      
    return 0;
}