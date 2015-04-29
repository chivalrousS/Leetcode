/**
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 ¡ú a2
                   ¨K
                     c1 ¡ú c2 ¡ú c3
                   ¨J
B:     b1 ¡ú b2 ¡ú b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
int getLength(ListNode* head)
    {
        int length = 0;
        ListNode* p = head;
        while(p != NULL)
        {
            p = p->next;
            ++length;
        }
        return length;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
            return NULL;
        int lengthA = getLength(headA);
        int lengthB = getLength(headB);
        ListNode* p = NULL;
        ListNode* q = NULL;
        int index = 0;
        if (lengthA > lengthB)
        {
            p = headA;
            q = headB;
            index = lengthA - lengthB;
        }
        else
        {
            p = headB;
            q = headA;
            index = lengthB - lengthA;
        }

        while(p !=NULL && index >0)
        {
            p = p->next;
            --index;
        }
        while(p!=NULL && q != NULL &&p->next != NULL && q->next !=NULL && p->val != q->val)
        {
            p = p->next;
            q = q->next;
        }
        if(p->val == q->val)
            return p;
        return NULL;
    }

};
