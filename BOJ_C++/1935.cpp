#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
double a[26];
int main() {
    fastio;
    int n; cin >> n;
    string str; cin >> str;
    for(int i = 0; i < n; i++) cin >> a[i];

    stack<double> st;
    for(auto &c : str) {
        double t1, t2;
        if(c == '*') {
            t1 = st.top(); st.pop();
            t2 = st.top(); st.pop();
            st.push(t1 * t2);
        } else if(c == '+') {
            t1 = st.top(); st.pop();
            t2 = st.top(); st.pop();
            st.push(t1 + t2);
        } else if(c == '/') {
            t1 = st.top(); st.pop();
            t2 = st.top(); st.pop();
            st.push(t2 / t1);
        } else if(c == '-') {
            t1 = st.top(); st.pop();
            t2 = st.top(); st.pop();
            st.push(t2 - t1);
        } else {
            st.push(a[c - 'A']);
        }
    }
    cout << fixed << setprecision(2); 
    cout << st.top() << '\n';

    return 0;
}