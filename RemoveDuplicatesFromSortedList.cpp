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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode* p = head;
        if(p==NULL||p->next == NULL)
          return head;
        ListNode* q = p->next;
        if(q->next == NULL)
        {
            if(p->val == q->val)
               p->next = NULL;
        }
        while(q->next != NULL)
        {
            if(p->val != q->val)
            {
                p = q;
                q = q->next;
            }
            if(p->val == q->val)
            {
                if(q->next != NULL)
                {
                  p->next = q->next;
                  q = p->next;
                }
                else
                {
                  p->next == NULL;  
                }
            }
        }
        if(p->val == q->val)
        {
            p->next = NULL;
        }
        return head;
        
    }
};