#include <stdio.h> 


struct node
{
	int value;
	struct node *next;
};


void print_list(struct node *head) {
	struct node *n = head;
	while (n->next != NULL) {
		n = n->next;
		printf("%d ", n->value);
	}
	printf("\n");
}


void insert_node(struct node *head, int value) { 
	/* adding node to the end of the list */
	struct node *last = head;
	while (last->next != NULL) { // finding last node
		last = last->next;
	}
	// inserting new node after last node
	last->next = malloc(sizeof(struct node));
	last->next->next = NULL;
	last->next->value = value;
}


void delete_node(struct node *head) {
	/* deleting first node */
	if (head->next == NULL)
		return;
	head->next = head->next->next;
}

void delete_last_node(struct node *head) {
	/* deleting first node */
	if (head->next == NULL)
		return;
	struct node *prelast = head;
	while (prelast->next->next != NULL) // finding last node
		prelast = prelast->next;
	prelast->next = NULL;
}


int main() {

	// create head 
	struct node *head;
	head = malloc(sizeof(struct node));
	head->value = -1; head->next = NULL;
    // insert 1, 2, 3, 4, 5 and then delete 1
	insert_node(head, 1);
	insert_node(head, 2);
	insert_node(head, 3);
	insert_node(head, 4);
	insert_node(head, 5);
	print_list(head);

	delete_node(head);
	print_list(head);

	return 0;
}


