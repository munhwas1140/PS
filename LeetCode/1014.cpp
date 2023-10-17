#include <bits/stdc++.h>
using namespace std;

// Best Sightseeing Pair

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int top = 0, ans = 0;
        for(int i = 0; i < values.size(); i++) {
            ans = max(ans, top + values[i]);
            top = max(top, values[i]) - 1;
        }
        return ans;
    }
};