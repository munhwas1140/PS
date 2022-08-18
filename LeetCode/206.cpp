#include <bits/stdc++.h>
using namespace std;

// Reverse Linked List

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = new ListNode(), *cur = head;
        
        while(cur) {
            ListNode *tmp = cur;
            cur = cur->next;
            tmp->next = pre->next;
            pre->next = tmp;
        }
        
        return pre->next;
    }
};