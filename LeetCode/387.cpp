#include <bits/stdc++.h>
using namespace std;

//First Unique Character in a String

class Solution {
public:
    int firstUniqChar(string s) {
        int check[26];
        memset(check,-1,sizeof(check));
        
        for(int i = 0; i < s.size(); i++) {
            int x = s[i] - 'a';
            if(check[x] == -1) {
                check[x] = i;
            } else {
                check[x] = -2;
            }
        }
        
        int ans = -1;
        for(int i = 0; i < 26; i++) {
            if(check[i] >= 0) {
                if(ans == -1 || check[i] < ans) {
                    ans = check[i];
                }
            }
        }
        return ans;
    }
};