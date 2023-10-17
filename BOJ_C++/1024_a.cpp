#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
ll f(string str) {
    ll ret = 0LL;
    ll now = 1LL;
    for(int i = str.size() - 1; i >= 0; i--) {
        ret += (ll)(str[i] - '0') * now;
        now *= 8LL;
    }
    return ret;
}

string ff(ll now) {
    if(now == 0) return "0";
    string ret = "";
    while(now) {
        ret = char(now % 8 + '0') + ret;
        now /= 8;
    }
    return ret;
}
int main() {
    fastio;
    string str, a, b;
    char op;
    cin >> str;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '-' && i == 0) continue;
        if(str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*') {
            op = str[i];
            a = str.substr(0,i);
            b = str.substr(i + 1);
            break;
        }
    }

    bool ma, mb;
    ma = mb = false;
    if(a.front() == '-') {
        ma = true;
        a = a.substr(1);
    }
    if(b.front() == '-') {
        mb = true;
        b = b.substr(1);
    }
    ll aa = f(a), bb = f(b);
    if(ma) aa *= -1;
    if(mb) bb *= -1;
    if(op == '+') aa += bb;
    else if(op == '*') aa *= bb;
    else if(op == '-') aa -= bb;
    else {
        if(bb == 0) {
            return !(cout << "invalid" << '\n');
        }
        if(aa < 0 && bb > 0) {
            aa = (aa - bb + 1) / bb;
        } else if(aa > 0 && bb < 0) {
            aa = (aa - bb - 1) / bb;
        } else {
            aa /= bb;
        }
    
    }
    ma = false;
    if(aa < 0) {
        aa *= -1;
        ma = true;
    }

    string ans = ff(aa);
    if(ma) ans = '-' + ans;
    cout << ans << '\n';

    return 0;
}