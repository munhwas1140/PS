#include <bits/stdc++.h>
using namespace std;

// Numbers With Same Consecutive Differences

class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        string s = "";
        go(ans, s, 0, n, k);
        return ans;
    }
    
    void go(vector<int> &ans, string &s, int sz, int n, int k) {
        if(sz == n) {
            ans.push_back(stoi(s));
            return ;
        } 
        for(char i = '0'; i <= '9'; i++) {
            if(sz == 0) {
                if(i == '0') continue;
                s.push_back(i);
                go(ans, s, sz + 1, n, k);
                s.pop_back();
            } else {
                if(abs(i - s.back()) == k) {
                    s.push_back(i);
                    go(ans, s, sz + 1, n , k);
                    s.pop_back();
                } 
            }
        }
        return ;
    }
};