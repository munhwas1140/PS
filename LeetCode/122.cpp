#include <bits/stdc++.h>
using namespace std;

// Best Time to Buy and Sell Stock II

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, have = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] < prices[i - 1]) {
                if(have != -1) {
                    ans += prices[i-1] - have;
                    have = -1;
                }
            } else if(prices[i] > prices[i - 1]) {
                if(have == -1) {
                    have = prices[i-1];
                }
            }
        }
        
        if(have != -1 && have < prices[prices.size() - 1]) {
            ans += prices[prices.size() - 1] - have;
        }
        return ans;
    }
};