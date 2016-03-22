/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) {
	if (head == NULL)
		return NULL;
	if (head->next == NULL)
		return head;
	struct node *temp = head,*temp1; int count = 0;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	int count1 = count;
	temp = head;
	for (int i = 0; i < count / 2; i++)
	{
		
		temp1 = temp;
		for (int j = 0; j < count1-1; j++)
		{
			temp1 = temp1->next;
		}
		int temp2 = temp->num;
		temp->num = temp1->num;
		temp1->num = temp2;
		temp = temp->next;
		count1-=2;
	}
	return head;
}
