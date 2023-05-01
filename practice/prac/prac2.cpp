#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> pos;
    for(int i = 0, tmp; i < m; i++) {
        cin >> tmp;
        for(int j = 0; j < tmp; j++) {
            pos.push_back(i % 2);
        }
    }
    int ans = 1e9;
    int cnt = 0;
    vector<int> tmp = a;
    for(int i = 0; i < n; i++) {

        if(tmp[i] != pos[i]) {
            for(int j = i + 1;;j++) {
                if(j == n) {
                    cnt = 1e9;
                    break;
                }
                cnt += 1;
                if(tmp[j] == pos[i]) {
                    tmp.erase(tmp.begin() + j);
                    tmp.insert(tmp.begin() + i, pos[i]);
                    break;
                }
            }
        }
    }
    ans = min(ans, cnt);
    
    tmp = a;
    cnt = 0;
    for(int i = 0; i < n; i++) {

        if(tmp[i] == pos[i]) {
            for(int j = i + 1;;j++) {
                if(j == n) {
                    cnt = 1e9;
                    break;
                }
                cnt += 1;
                if(tmp[j] != pos[i]) {
                    tmp.erase(tmp.begin() + j);
                    tmp.insert(tmp.begin() + i, 1 - pos[i]);
                    break;
                }
            }
        }
    }
    ans = min(ans, cnt);
    
    cout << ans << '\n';

    return 0;
}