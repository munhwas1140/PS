#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

vector<int> ans;
string str;
int n;
int sz;
bool check[51];
bool go(int now) {
    if(now == n) {
        return true;
    }

    string subs = str.substr(now, 1);
    int t = stoi(subs);
    if(t <= sz && !check[t]) {
        check[t] = true;
        ans.push_back(t);
        if(go(now + 1)) return true;
        ans.pop_back();
        check[t] = false;
    } 
    
    if(now < n - 1) {
        subs = str.substr(now, 2);
        t = stoi(subs);
        if(t <= sz && !check[t]) {
            check[t] = true;
            ans.push_back(t);
            if(go(now + 2)) return true;
            ans.pop_back();
            check[t] = false;
        }
    }
    return false;
}
int main() {
    fastio;
    cin >> str;
    n = str.size();
    if(n <= 9) sz = n;
    else sz = (n - 9) / 2 + 9;
    go(0);
      
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}