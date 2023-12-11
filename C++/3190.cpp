#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    set<pair<int,int>> apple;
    for(int i = 0; i < k; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        apple.insert(make_pair(t1,t2));
    }

    int l;
    cin >> l;
    vector<pair<int, char>> change(l);
    for(auto &[t, dir] : change) cin >> t >> dir;
    int i = 0; 

    deque<pair<int,int>> snake;
    snake.push_back({1,1});
    int nowd = 0;
    int t;
    for(t = 1; ;t++) {
        auto [x, y] = snake.back();
        int nx = x + dx[nowd];
        int ny = y + dy[nowd];
        if(change[i].first == t) {
            if(change[i].second == 'L') {
                nowd = (nowd + 3) % 4;
            } else {
                nowd = (nowd + 1) % 4;
            } 
            i++;
        }
        
        if(nx < 1 || nx > n || ny < 1 || ny > n) break;
        snake.push_back({nx,ny});
        for(int i = 0; i < snake.size() - 1; i++) {
            if(snake[i] == snake.back()) return !(cout << t << '\n'); 
        }

        auto it = apple.find({nx,ny});
        if(it == apple.end()) {
            snake.pop_front();
        } else {
            apple.erase(it);
        }
        
    }
    cout << t<< '\n';
    return 0;
}