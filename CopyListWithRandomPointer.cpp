/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head)
			return NULL;
		RandomListNode *copyHead=NULL,*copyCurrent=NULL;
		RandomListNode *current = head;
		while (current)
		{
			if (current == head)
			{
				copyHead = new RandomListNode(head->label);
				copyCurrent = copyHead;
			}
			else
			{
				RandomListNode *rNode = new RandomListNode(current->label);
				copyCurrent = rNode;
			}
			copyCurrent->next = current->next;
			current->next = copyCurrent;
			current = copyCurrent->next;
		}

		current = head;
		while (current)
		{
			if (current->random)
			{
				current->next->random = current->random->next;
			}
			current = current->next->next;
		}
		current = head;
		copyCurrent = copyHead;
		while (current)
		{
			current->next = copyCurrent->next;
			current = current->next;
			if (!current)
				break;
			copyCurrent->next = current->next;
			copyCurrent = copyCurrent->next;
		}
		return copyHead;

    }
};
