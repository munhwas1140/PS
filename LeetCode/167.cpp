#include <bits/stdc++.h>
using namespace std;

// Two Sum II - Input Array Is Sorted

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int r = numbers.size() - 1;
        int l = 0;
        while(true) {
            int a = numbers[l] + numbers[r];
            if(a == target) {
                return vector<int>({l + 1, r + 1});
            } else if(a < target) {
                l += 1;
            } else {
                r -= 1;
            }
        }
        return vector<int>();
    }
};