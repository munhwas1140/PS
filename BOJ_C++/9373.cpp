#include <bits/stdc++.h>
using namespace std;

struct asdf {
	int x, y, r;
};
vector<pair<int, double>> g[5000];
bool visited[5000];
int p[5000];
int find(int x) {
	if(p[x] < 0) return x;
	return p[x] = find(p[x]);
}
void set_union(int x, int y) {
	x = find(x);
	y = find(y);
	if(x == y) return ;
	p[x] = y;
}
double calc(asdf &a, asdf &b) {
	double t1 = (a.x - b.x) * (a.x - b.x);
	double t2 = (a.y - b.y) * (a.y - b.y);
	double t3 = sqrt(t1 + t2);
	return (t3 - a.r - b.r > 0.0 ? t3 - a.r - b.r : 1e9);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	while(tc--) {
		for(int i = 0; i < 5000; i++) g[i].clear();
		int w, n;
		cin >> w >> n;
		if(n == 0) {
			cout << w / 2 << '\n';
			continue;
		}
		vector<asdf> a(n);
		for(int i = 0; i < n; i++) {
			cin >> a[i].x >> a[i].y >> a[i].r;
		}
		if(n == 1) {
			double t1 = a[0].x - a[0].r;
			double t2 = w - a[0].x - a[0].r;
			if(t1 < 0 && t2 < 0) cout << -1 << '\n';
			else if(t1 < 0) cout << t2 << '\n';
			else if(t2 < 0) cout << t1 << '\n';
			else cout << min(t1, t2) << '\n';
			continue;
		}	
		sort(a.begin(), a.end(), [](auto &a, auto &b) {
			return a.y < b.y;
		});
		
		priority_queue<tuple<double, int, int>> pq;
		
		int cnt = 0;	
		double pl, pr,pdis;
		for(int i = 0; i < n; i++) {
			double l = (a[i].x - a[i].r > 0.0 ? a[i].x - a[i].r : 1e9);
			double r = (w - a[i].x - a[i].r > 0.0 ? w - a[i].x - a[i].r : 1e9);
			double dis;
			if(i < n - 1) {
				dis = calc(a[i], a[i+1]);
				if(dis == 1e9 || l == 1e9) {
					pq.push({-1e9, 3 * i + 2, 3 * i});
				} else {
					pq.push({-min(dis,l), 3 * i + 2, 3 * i});
				}

				if(dis == 1e9 || r == 1e9) {
					pq.push({-1e9, 3 * i + 2, 3 * i + 1});
				} else {
					pq.push({-min(dis,r), 3 * i + 2, 3 * i + 1});
				}
			}
			if(i > 0) {
				if(pdis == 1e9 || l == 1e9) {
					pq.push({-1e9, 3 * i, 3 * (i - 1) + 2});
				} else {
					pq.push({-min(pdis, l), 3 * i, 3 * (i - 1) + 2});
				}
				if(pdis == 1e9 || r == 1e9) {
					pq.push({-1e9, 3 * i + 1, 3 * (i - 1) + 2});
				} else {
					pq.push({-min(pdis, r), 3 * i + 1, 3 * (i - 1) + 2});
				}
				if(pl == 1e9 || l == 1e9) {
					pq.push({-1e9, 3 * i, 3 * (i - 1)});
				} else {
					pq.push({-min(pl, l), 3 * i, 3 * (i - 1)});
				}
				if(pr == 1e9 || r == 1e9) {
					pq.push({-1e9, 3 * i + 1, 3 * (i - 1) + 1});
				} else {
					pq.push({-min(pr, r), 3 * i + 1, 3 * (i - 1) + 1});
				}
			}
			pdis = dis;
			pl = l;
			pr = r;
		}
		int c = 0;
		memset(p,-1,sizeof(p));
		while(c < 3 * n - 2) {
			auto [d, x, y] = pq.top();
			pq.pop();
			int tx = x;
			int ty = y;
			d = -d;
			x = find(x);
			y = find(y);
			if(x != y) {
				set_union(x, y);
				c++;
				g[tx].push_back({ty, d});
				g[ty].push_back({tx, d});
			}
		}
		memset(visited,false,sizeof(visited));	
		queue<pair<double, int>> q;
		double ans = 1e9;
		if(a[0].x - a[0].r > 0) {
			q.push({1e9 + 7, 0});
			visited[0] = true;
			while(!q.empty()) {
				auto [mind, now] = q.front();
				q.pop();
				if(now == 3 * (n - 1) || now == 3 * (n - 1) + 1) {
					ans = min(ans, mind);
				}
				for(auto &[next, nd] : g[now]) {
					if(!visited[next] && nd != 1e9) {
						visited[next] = true;
						q.push({min(nd, mind), next});
					}	
				}
			}
		}	

		memset(visited, false,sizeof(visited));
		if(w - a[0].x - a[0].r > 0) {
			q.push({1e9 + 7, 1});
			visited[1] = true;
			while(!q.empty()) {
				auto [mind, now] = q.front();
				q.pop();
				if(mind == 1e9) continue;
				if(now == 3 * (n - 1) || now == 3 * (n - 1) + 1) {
					ans = min(ans, mind);
				}
				for(auto &[next, nd] : g[now]) {
					if(!visited[next] && nd != 1e9) {
						visited[next] = true;
						q.push({min(nd, mind), next});
					}	
				}
			}
		}
		cout << fixed << setprecision(6);
		if(ans == 1e9) cout << 0 << '\n';
		else cout << ans / 2 << '\n';
	}
	
	return 0;
#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
struct asdf {
	double x, y, r;
};
int p[1010];
int find(int x) {
	if(p[x] < 0) return x;
	return p[x] = find(p[x]);
}
void set_union(int x, int y) {
	x = find(x);
	y = find(y);
	if(x == y) return ;
	p[x] = y;
}
double dist(asdf &a, asdf &b) {
	double t1 = (a.x - b.x) * (a.x - b.x);
	double t2 = (a.y - b.y) * (a.y - b.y);
	return (sqrt(t1 + t2) - a.r - b.r > 0 ? sqrt(t1 + t2) - a.r - b.r : 0.0);
}
int main() {
	fastio;
	int tc; cin >> tc;
	while(tc--) {
		double w;
		int n;
		cin >> w >> n;
		vector<asdf> a(n);
		for(int i = 0; i < n; i++) {
			cin >> a[i].x >> a[i].y >> a[i].r;
		}	
		if(n == 0) {
			cout << w / 2 << '\n';
			continue;
		}
		sort(a.begin(), a.end(), [](auto &a, auto &b) {
			return a.y < b.y;
		});
		priority_queue<tuple<double, int ,int>> pq;	
		for(int i = 0; i < n; i++) {
			double t1 = (a[i].x - a[i].r > 0 ? a[i].x - a[i].r : 0.0);
			double t2 = (w - a[i].x - a[i].r > 0 ? w - a[i].x - a[i].r : 0.0);
			pq.push({-t1, i, n});
			pq.push({-t2, i, n + 1});
			for(int j = i + 1; j < n; j++) {
				double t = dist(a[i], a[j]);
				pq.push({-t, i, j});
			}
		}

		memset(p,-1,sizeof(p));
		while(true) {
			auto [d, x, y] = pq.top();
			pq.pop();
			x = find(x);
			y = find(y);
			if(x != y) {
				set_union(x, y);
			}	
			if(find(n) == find(n + 1)) {
				cout << fixed << setprecision(6);
				cout << (-d) / 2 << '\n';
				break;
			}
		}
	}
	return 0;
}}