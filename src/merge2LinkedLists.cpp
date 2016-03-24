#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {


	struct node* result = NULL;

	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	if (head1->num >= head2->num)
	{
		result = head2;
		result->next = merge2LinkedLists(head1, head2->next);
	}
	else
	{
		result = head1;
		result->next = merge2LinkedLists(head2, head1->next);
	}
	return result;
}