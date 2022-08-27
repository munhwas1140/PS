#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nameSize[21];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<string> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    queue<int> q;
    for(int i = 0; i < n; i++) {
        q.push(a[i].size());
        if(q.size() > k + 1) {
            nameSize[q.front()] -= 1;
            q.pop();
        }
        ans += nameSize[q.back()];
        nameSize[q.back()] += 1;
    }
    cout << ans << '\n';
      
    return 0;
}