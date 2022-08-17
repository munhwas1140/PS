#include <bits/stdc++.h>
using namespace std;

// Reverse String

class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0;
        int r = s.size() - 1;
        while(l <= r) {
            swap(s[l], s[r]);
            l += 1;
            r -= 1;
        }
    }   
};