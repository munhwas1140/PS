#include <bits/stdc++.h>
using namespace std;

// Remove Duplicates from Sorted List
 
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *ans = head;
        
        while(head) {
            if(head->next && head->val == head->next->val) {
                int v = head->val;
                ListNode *p = head;
                while(p->next && p->next->val == v) {
                    p = p->next;
                }
                head->next = p->next;
            }
            head = head->next;
        }
        
        return ans;
    }
};