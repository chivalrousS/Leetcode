/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* h1 = NULL,*e1 = NULL,*h2 = NULL,*e2 = NULL;
        if(head == NULL)
            return head;
        for(;head;head = head->next)
        {
            if(head->val < x)
            {
                if(e1)
                    e1 = e1->next = head;
                else
                    h1 = e1 = head;
            }
            else if(e2)
                e2 = e2->next = head;
            else
            {
                h2 = e2 = head;
            }
        }
        if(e2)
            e2->next = NULL;
        if(e1)
            e1->next = h2;
        return h1?h1:h2;

    }
};
