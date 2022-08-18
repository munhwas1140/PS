#include <bits/stdc++.h>
using namespace std;

// Reduce Array Size to The Half

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        
        int cnt[100001] = {0};
        for(int x : arr) {
            cnt[x] += 1;
        }
        priority_queue<int> pq;
        for(int i = 0; i < 100001; i++) {
            if(cnt[i]) pq.push(cnt[i]);
        }
        
        int num = 0;
        int ans;
        for(ans = 1; num < n / 2; pq.pop(), ans += 1) {
            num += pq.top();
        }
        return ans - 1;
    }
};