#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while(1) {
        int n, m;
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        vector<vector<int>> a(n,vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }

        int ans = 0;
        stack<tuple<int,int,int>> st;
        int start;
        for(int i = 0; i < n; i++) {
            start = - 1;
            for(int j = 0; j < m; j++) {
                if(a[i][j] && i < n - 1 && a[i+1][j]) a[i+1][j] = a[i][j] + 1;
                if(a[i][j] == 0) {
                    start = j;
                    while(!st.empty()) {
                        auto &[hei,idx,nowst] = st.top();
                        st.pop();
                        if(st.empty()) ans = max(ans, hei * (j - nowst - 1));
                        else ans = max(ans, hei * (j - get<1>(st.top()) - 1));
                    }
                    continue;
                }

                while(!st.empty() && get<0>(st.top()) > a[i][j]) {
                    auto &[hei,idx,nowst] = st.top();
                    st.pop();
                    if(st.empty()) ans = max(ans, hei * (j - nowst - 1));
                    else ans = max(ans, hei * (j - get<1>(st.top()) - 1));
                }
                st.push({a[i][j],j,start});
            }
            
            while(!st.empty()) {
                auto &[hei,idx,nowst] = st.top();
                st.pop();
                if(st.empty()) ans = max(ans, hei * (m - nowst - 1));
                else ans = max(ans, hei * (m - get<1>(st.top()) - 1));
            }
        }
        cout << ans << '\n';
    }     
      
    return 0;
}