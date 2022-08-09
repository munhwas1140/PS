#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;
    int tmp;
    cin >> tmp;
    left.push(tmp);
    cout << tmp << '\n';
    for(int i = 1; i < n; i++) {
        cin >> tmp;
        if(tmp < left.top()) {
            left.push(tmp);
        } else {
            right.push(tmp);
        }

        if(i % 2 == 1) {
            if(left.size() == right.size() + 2) {
                right.push(left.top());
                left.pop();
            }
        } else {
            if(right.size() > left.size()) {
                left.push(right.top());
                right.pop();
            }
        }

        cout << left.top() << '\n';
    }
    return 0;
}