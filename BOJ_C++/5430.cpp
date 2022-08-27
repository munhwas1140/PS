#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    while(tc--) {
        bool front = true;
        string op; int n;
        cin >> op >> n;
        deque<int> a(n);
        

        string str;
        cin >> str;
        stringstream ss(str);
        char tmp; 
        for(int i = 0; i < n; i++) {
            ss >> tmp >> a[i];
        }

        bool ok = true;
        for(char &q : op) {
            if(q == 'R') {
                front = !front;
            } else {
                if(a.empty()) {
                    ok = false;
                    break;
                }
                if(front) {
                    a.pop_front();
                } else {
                    a.pop_back();
                } 
            }
        }

        if(ok) {
            cout << '[';
            if(front) {
                for(int i = 0; i < a.size(); i++) {
                    cout << a[i];
                    if(i != a.size() - 1) cout << ',';
                }
            } else {
                for(int i = a.size() - 1; i >= 0; i--) {
                    cout << a[i];
                    if(i != 0) cout << ',';
                }
            }
            cout << "]\n";

        } else {
            cout << "error" << '\n';
        }
    }    
      
    return 0;
}