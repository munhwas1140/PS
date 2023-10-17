#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k; 
    deque<char> dq(n, '?');

    bool flag = false;

    while(k--) {
        int a;
        char c;
        cin >> a >> c;
        for(int i = 0; i < a; i++) {
            dq.push_front(dq.back());
            dq.pop_back();
        }
        if(dq.front() == '?') {
            dq.front() = c;
        } else if(dq.front() != c) flag = true;
    }    

    int check[255] = {0};
    for(int i = 0; i < dq.size(); i++) {
        if(dq[i] == '?') continue;
        if(check[dq[i]]) flag = true;
        check[dq[i]] += 1;
        }

        if(flag) return !(cout << '!' << '\n');
        for(int i = 0; i < dq.size(); i++) {
            cout << dq[i];
    }
    cout << '\n';

      
    return 0;
}