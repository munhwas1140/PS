#include <bits/stdc++.h>
using namespace std;

// Word Ladder II

class Solution {
public:
    vector<int> g[502];
    vector<int> p[502];
    int dist[502];
    bool visited[502];
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        memset(dist,-1,sizeof(dist));
        memset(visited,false,sizeof(visited));
        for(int i = 0; i < 502; i++) {
            g[i].clear();
            p[i].clear();
        }
        
        vector<vector<string>> ans;
        wordList.insert(wordList.begin(), beginWord);
        
        int last = -1;
        for(int i = 0; i < wordList.size(); i++) {
            if(wordList[i] == endWord) last = i;
        }
        if(last == -1) return ans;
        
        for(int i = 0; i < wordList.size(); i++) {
            for(int j = i + 1; j< wordList.size(); j++) {
                if(check(wordList[i], wordList[j])) {
                    g[i].push_back(j);
                    g[j].push_back(i);      
                }
            }
        }
        
        queue<int> q;
        q.push(0);
        dist[0] = 0;
        
        while(!q.empty()) {
            int now = q.front();
            q.pop();
            for(int next : g[now]) {
                if(dist[next] == -1 || dist[next] > dist[now] + 1) {
                    dist[next] = dist[now] + 1;
                    q.push(next);
                    p[next].push_back(now);
                } else if(dist[next] == dist[now] + 1) {
                    p[next].push_back(now);
                }
            }
        }
        vector<string> tmp;
        go(ans, wordList, tmp, last);
        
        
        return ans;
    }
    
    void go(vector<vector<string>> &ans, vector<string> &wordList, vector<string> &tmp, int idx) {
        
        tmp.push_back(wordList[idx]);
        if(idx == 0) {
            reverse(tmp.begin(), tmp.end());
            ans.push_back(tmp);
            reverse(tmp.begin(), tmp.end());
            tmp.pop_back();
            return ;
        }
        visited[idx] = true;
        for(int next : p[idx]) {
            if(!visited[next]) {
                go(ans, wordList, tmp, next);
            }
        }
        visited[idx] = false;
        tmp.pop_back();
    }
    
    
    bool check(string &a, string &b) {
        int cnt = 0;
        for(int i = 0; i < a.size(); i++) {
            if(a[i] != b[i]) cnt += 1;
        }
        return cnt == 1;
    }
    
};