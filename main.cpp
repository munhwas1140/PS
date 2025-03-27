#include <bits/stdc++.h>
using namespace std;

struct Node {
    unordered_map<int, int> count;
    Node* next[26] = {};
};

vector<int> solution(vector<string> words, vector<string> queries) {
    Node* g = new Node();
    Node* r_g = new Node();

    for (const string& word : words) {
        Node* node = g;
        Node* r_node = r_g;

        int sz = word.size();
        g->count[sz]++;
        r_g->count[sz]++;

        for (int i = 0; i < sz; i++) {
            int value = word[i] - 'a';
            int r_value = word[sz - i - 1] - 'a';

            if (!node->next[value]) {
                node->next[value] = new Node();
            }

            if (!r_node->next[r_value]) {
                r_node->next[r_value] = new Node();
            }

            node = node->next[value];
            node->count[sz]++;

            r_node = r_node->next[r_value];
            r_node->count[sz]++;
        }
    }

    vector<int> ans;
    for (const string& q : queries) {
        int sz = q.size();
        int result = 0;

        if (q.front() == '?' && q.back() == '?') {
            result = g->count[sz];
        } else if (q.front() == '?') {
            Node* node = r_g;
            for (int i = sz - 1; i >= 0 && node; i--) {
                if (q[i] == '?') {
                    result = node->count[sz];
                    break;
                }
                node = node->next[q[i] - 'a'];
            }
        } else if (q.back() == '?') {
            Node* node = g;
            for (int i = 0; i < sz && node; i++) {
                if (q[i] == '?') {
                    result = node->count[sz];
                    break;
                }
                node = node->next[q[i] - 'a'];
            }
        }
        ans.push_back(result);
    }
    return ans;
}