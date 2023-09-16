#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct Node {
    int data;
    struct Node* next;
};
void appendNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode; // If the list is empty, make the new node the head.
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}
void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
void MoveNode(struct Node** destRef,struct Node** sourceRef);
struct Node* SortedMerge(struct Node* a, struct Node* b){
	struct Node dummy;
	struct Node* tail = &dummy;
	dummy.next = NULL;
	while (1) {
		if (a == NULL) {
			tail->next = b;
			break;
		}
		else if (b == NULL) {
			tail->next = a;
			break;
		}
		if (a->data <= b->data) MoveNode(&(tail->next), &a);
		else MoveNode(&(tail->next), &b);
		tail = tail->next;
	}
	return (dummy.next);
}
void MoveNode(struct Node** destRef,struct Node** sourceRef){
	struct Node* newNode = *sourceRef;
	assert(newNode != NULL);
	*sourceRef = newNode->next;
	newNode->next = *destRef;
	*destRef = newNode;
}
void push(struct Node** head_ref, int new_data){
	struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}
int main() {
    struct Node* head = NULL; // Initialize an empty linked list.
    struct Node* head1=NULL;
    struct Node* res=NULL;
    int input;

    printf("Enter elements for the linked list (enter -1 to stop):\n");

    while (1) {
        printf("Enter an element: ");
        scanf("%d", &input);

        if (input == -1) {
            break; // Exit the loop when the user enters -1.
        }

        appendNode(&head, input); // Add the input to the linked list.
    }

    printf("Linked list elements: ");
    displayList(head);
     printf("Enter elements for the 2nd linked list (enter -1 to stop):\n");

    while (1) {
        printf("Enter an element: ");
        scanf("%d", &input);

        if (input == -1) {
            break; // Exit the loop when the user enters -1.
        }

        appendNode(&head1, input); // Add the input to the linked list.
    }

    printf("Linked list elements: ");
    displayList(head1);
    res = SortedMerge(head,head1);
	printf("Merged Linked List is: \n");
	displayList(res);
    // Free the memory allocated for the linked list nodes.
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
