#include <bits/stdc++.h>
using namespace std;

// Palindrome Linked List

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        ListNode *tmp = head;
        while(tmp) {
            s.push(tmp->val);
            tmp = tmp->next;
        }
        
        int n = s.size();
        for(int i = 0; i < n / 2; i++) {
            if(s.top() != head->val) return false;
            head = head->next;
            s.pop();
        }
        return true;
    }
};