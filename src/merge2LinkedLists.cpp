/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<malloc.h>
struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if (head1==NULL && head2==NULL)
	return NULL;
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	struct node *temp = head1;
	int len1 = 0, len2 = 0;
	while (temp != NULL)
	{
		len1++;
		temp = temp->next;
	}
	temp = head2;
	while (temp != NULL)
	{
		len2++;
		temp = temp->next;
	}
	struct node *res = (struct node *)malloc((len1+len2)*sizeof(struct node)),*res1=res;
	res->num = 0; res->next = NULL;
	int i = 0, j = 0;
	while (head1!=NULL && head2!=NULL)
	{
		if (head1->num < head2->num)
		{
			res->num = head1->num;
			res->next = head1->next;
			head1 = head1->next;
			if (res->next != NULL)
			res = res->next;
		}
		else if (head1->num > head2->num)
		{
			res->num = head2->num;
			res->next = head2->next;
			head2 = head2->next;
			if (res->next != NULL)
			res = res->next;
		}
		else
		{
			res->num = head2->num;
			res->next = head2->next;
			head2 = head2->next;
			head1 = head1->next;
			if (res != NULL)
			res = res->next;
		}


	}
	while (head1 != NULL)
	{
		res->num = head1->num;
		res->next = head1->next;
		head1 = head1->next;
		if (res->next!=NULL)
		res = res->next;
	}
	while (head2 != NULL)
	{
		res->num = head2->num;
		res->next = head2->next;
		head2 = head2->next;
		if (res->next != NULL)
		res = res->next;
	}
	return res1;

}
