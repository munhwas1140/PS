#include <bits/stdc++.h>
using namespace std;

// Stamping The Sequence

class Solution {
public:
    int check(string &stamp, string &target, int pos) {
        int cnt = 0;
        for(int i = 0; i < stamp.size(); i++) {
            char c = target[pos + i];
            if(c == '?') continue;
            else if(c == stamp[i]) cnt += 1;
            else return -1;
        }
        return cnt;
    }    
    
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> ret;
        int sz = stamp.size();
        
        for(int i = 0; i <= target.size() - sz; i++) {
            if(check(stamp, target, i) >= 1) {
                fill(target.begin() + i, target.begin() + i + sz, '?');
                ret.push_back(i);
            }
        }
        
        reverse(stamp.begin(), stamp.end());
        reverse(target.begin(), target.end());
        
        for(int i = 0; i <= target.size() - sz; i++) {
            if(check(stamp, target, i) >= 1) {
                fill(target.begin() + i, target.begin() + i + sz, '?');
                ret.push_back(target.size() - sz - i);
            }
        }
        
        reverse(ret.begin(), ret.end());
        if(target == string(target.size(), '?')) return ret;
        return vector<int>();
    }
};