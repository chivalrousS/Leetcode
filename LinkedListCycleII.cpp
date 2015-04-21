/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head ==NULL)
            return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next && fast && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
               {
                 slow = head;
                 while(fast != slow)
                  {
                  fast = fast->next;
                  slow = slow->next;
                  }
                  return fast;
               }
                   
        }
     return NULL;
    }
};