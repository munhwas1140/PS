#include <bits/stdc++.h>
using namespace std;
void sub(string &str, char c) {
	int n = str.size();
	for(int i =	n - 1; i >= 0; i--) {
		if(str[i] - c >= 0) {
			str[i] = (str[i] - c) + '0';
			break;
		}
		str[i] = (str[i] - c + 10) + '0';
        c = '1';
	}

	if(n != 1 && str[0] == '0') {
		str = str.substr(1);
	}
	return ;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int tc; cin >> tc;
	while(tc--) {
		string str; cin >> str;
		string ans = "";

		while(str.size() != 1) {
            ans = str.back() + ans;
            str.pop_back();
			sub(str, ans.front());
		}

		if(str == "0") cout << ans << '\n';
		else cout << 0 << '\n';
	}

	return 0;
}