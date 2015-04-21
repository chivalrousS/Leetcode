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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) 
    {
        if(l1 == NULL)
           return l2;
        if(l2 == NULL)
           return l1;
        
        ListNode* MergeHead = NULL;
        if(l1->val <= l2->val)
            {
                MergeHead = l1;
                MergeHead->next = mergeTwoLists(l1->next,l2);
            }
        else
            {
                MergeHead = l2;
                MergeHead->next = mergeTwoLists(l1,l2->next);
            }
        return MergeHead;
    }
};