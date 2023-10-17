#include <bits/stdc++.h>
using namespace std;

// Minimum Numbers of Refueling Stops

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        long long cur = startFuel;
        int cnt;
        int i = 0;
        priority_queue<int> pq;
        for(cnt = 0; cur < target ; cnt++) {
            while(i < stations.size() && cur >= stations[i][0]) {
                pq.push(stations[i++][1]);
            }
            if(pq.empty()) return -1;
            cur += pq.top(); pq.pop();
        }
        return cnt;
    }
};