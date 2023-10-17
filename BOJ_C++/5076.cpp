#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while(true) {
        string str;
        getline(cin, str);
        if(str[0] == '#' && str.size() == 1) {
           break;
        }

        stack<string> S;
        bool ok = true;
        for(int i = 0; i < str.size(); i++) {
            if(str[i] == '<') {        
                string tmp = "";
                while(i < str.size() && str[i] != '>') {
                    tmp += str[i];
                    i += 1;
                }
                if(i == str.size()) {
                    ok = false;
                    break;
                }
                tmp += str[i];
                if(tmp.substr(0,3) == "<br") continue;
                
                if(tmp.substr(0,2) == "</") {
                    tmp = '<' + tmp.substr(2);
                    if(!S.empty() && S.top() == tmp) {
                        S.pop();
                    } else {
                        ok = false;
                        break;
                    }
                } else if(tmp.substr(0,2) == "<a") {
                    S.push("<a>");
                } else {
                    S.push(tmp);
                }
            }
        }

        if(ok && S.empty()) {
            cout << "legal" << '\n';
        } else {
            cout << "illegal" << '\n';
        }
    }
    return 0;
}