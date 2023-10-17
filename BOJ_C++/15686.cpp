#include <bits/stdc++.h>
using namespace std;
int a[50][50];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> people;
    vector<pair<int,int>> chicken;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            if(a[i][j] == 1) people.push_back({i,j});
            else if(a[i][j] == 2) chicken.push_back({i,j});
        }
    } 
    vector<int> seq(chicken.size() - k);
    for(int i = 0; i < k; i++) {
        seq.push_back(1);
    }
    int ans = 1e9;    
    do {
        vector<int> v(people.size(), 1e9);

        for(int i = 0; i < chicken.size(); i++) {
            int cx = chicken[i].first;
            int cy = chicken[i].second;
            if(seq[i]) {
                for(int j = 0; j < people.size(); j++) {
                    int px = people[j].first;
                    int py = people[j].second;
                    v[j] = min(v[j], abs(px-cx) + abs(py-cy));
                }
            } 
        }
        int tmp = 0;
        for(int &x : v) tmp += x;
        ans = min(ans,tmp);
        
    } while(next_permutation(seq.begin(), seq.end()));
    cout << ans << '\n';
    return 0;
}
