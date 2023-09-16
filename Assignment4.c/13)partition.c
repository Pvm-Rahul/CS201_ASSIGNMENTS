#include <stdio.h>
#include <stdlib.h>

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
void partition(struct Node* head, int x){
	struct Node *smallerHead = NULL, *smallerLast = NULL;
	struct Node *greaterLast = NULL, *greaterHead = NULL;
	struct Node *equalHead = NULL, *equalLast = NULL;
	while (head != NULL) {
		if (head->data == x) {
			if (equalHead == NULL) equalHead = equalLast = head;
			else {
				equalLast->next = head;
				equalLast = equalLast->next;
			}
		}
		else if (head->data < x) {
			if (smallerHead == NULL) smallerLast = smallerHead = head;
			else {
				smallerLast->next = head;
				smallerLast = head;
			}
		}
		else{
			if (greaterHead == NULL) greaterLast = greaterHead = head;
			else {
				greaterLast->next = head;
				greaterLast = head;
			}
		}
		head = head->next;
	}
	if (greaterLast != NULL) greaterLast->next = NULL;
	if (smallerHead == NULL) {
		if (equalHead == NULL)  displayList(greaterHead);
		equalLast->next = greaterHead;
		displayList(equalHead);
	}
	if (equalHead == NULL) {
		smallerLast->next = greaterHead;
		displayList(smallerHead);
	}
	smallerLast->next = equalHead;
	equalLast->next = greaterHead;
	displayList(smallerHead);
}
int main() {
    struct Node* head = NULL; // Initialize an empty linked list.
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
    int x;
    printf("enter the node number for partition\n"); scanf("%d",&x);
    partition(head, x);
    // Free the memory allocated for the linked list nodes.
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
