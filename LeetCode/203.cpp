#include <bits/stdc++.h>
using namespace std;

// Remove Linked List Elements

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *p = new ListNode();
        ListNode **ans = &(p->next);
        p->next = head;
        while(p->next) {
            if(p->next->val == val) {
                ListNode *tmp = p->next;
                p->next = tmp->next;
                delete tmp;
            } else {
                p = p->next;
            }
        }
        return *ans;
    }
};