#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
string a, b;
int n, m;
bool check(vector<char> &cv, int c) {
    int sz = cv.size();
    if(sz < n) return false;
    string tmp = "";
    
    if(!c) {
        for(int i = 0; i < n; i++) {
            tmp += cv[sz - n + i];
        }
    } else {
        for(int i = 0; i < n; i++) {
            tmp += cv[sz - i - 1];
        }
    }
    if(tmp == a) return true;
    return false;
}
int main() {
    fastio;
    cin >> a >> b;
    n = a.size();
    m = b.size();
    vector<char> lv;
    vector<char> rv;
    int l = 0, r = m - 1;
    while(l <= r) {
        while(l <= r) {
            lv.push_back(b[l++]);
            if(check(lv,0)) {
                for(int j = 0; j < n; j++) {
                    lv.pop_back();
                }
                break;
            }
        }

        while(l <= r) {
            rv.push_back(b[r--]);
            if(check(rv,1)) {
                for(int j = 0; j < n; j++) {
                    rv.pop_back();
                }
                break;
            }
        }
    }
    
    while(!rv.empty()) {
        lv.push_back(rv.back()); rv.pop_back();
        if(check(lv,0)) {
            for(int i = 0; i < n; i++) {
                lv.pop_back();
            }
        }
    }
    
    for(int i = 0; i < lv.size(); i++) {
        cout << lv[i];
    }
    return 0;
}