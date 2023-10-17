#include <bits/stdc++.h>
using namespace std;

// Ugly Number II

class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 1) return 1;
        vector<int> a(n);
        
        int t2 = 0, t3 = 0, t5 = 0;
        a[0] = 1;
        for(int i = 1; i < n; i++) {
            a[i] = min({a[t2] * 2, a[t3] * 3, a[t5] * 5});
            if(a[i] == a[t2] * 2) t2++;
            if(a[i] == a[t3] * 3) t3++;
            if(a[i] == a[t5] * 5) t5++;
        }
        return a[n-1];
    }    
};