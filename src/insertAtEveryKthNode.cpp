/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {
	if (head == NULL)
		return NULL;
	if (K < 1)
		return NULL;
	struct node *temp;
	
	int count = 1,len=0;
	temp = head;
	while (temp != NULL)
	{
		len++;
		temp = temp->next;
	}
	if (K > len)
		return head;
	temp = head;
	
	while (temp != NULL)
	{
		if (count%K == 0)
		{
			struct node *new_node = (struct node *)malloc(sizeof(struct node));
			new_node->num = K;
			new_node->next = temp->next;
			temp->next = new_node;
			temp = temp->next;
		}
		temp = temp->next;
		count++;
	}
	return head;
}
