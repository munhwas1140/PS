#include <bits/stdc++.h>
using namespace std;

// Remove Nth Node From End of List

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// two pointer solution

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *ans = new ListNode();
        ans->next = head;
        
        ListNode *p, *q;
        p = q = ans;
        while(n--) p = p->next;
        
        if(!p->next) {
            q->next = q->next->next;
        }
        
        while(p->next) {
            p = p->next;
            q = q->next;
            if(!p->next) {
                q->next = q->next->next;
                break;
            }
            
        }
        return ans->next;
    }
};

// recursive sorution

// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         ListNode *root = new ListNode();
//         root->next = head;
//         remove(root, n);
        
//         return root->next;
//     }
    
//     int remove(ListNode *node,int n ) {
//         if(node == NULL) {
//             return 1;
//         }
//         int ans = 0;
//         ans += remove(node->next, n);
//         if(ans == n + 1) {
//             node->next = node->next->next;
//             return 1e9;
//         }
//         return ans + 1;
//     }
// };