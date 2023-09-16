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
long long multiplyTwoLists(struct Node* first,struct Node* second){
	long long N = 1000000007;
	long long num1 = 0, num2 = 0;
	while (first || second) {
		if (first) {
			num1 = ((num1)*10) % N + first->data;
			first = first->next;
		}
		if (second) {
			num2 = ((num2)*10) % N + second->data;
			second = second->next;
		}
	}
	return ((num1 % N) * (num2 % N)) % N;
}
int main() {
    struct Node* head = NULL; // Initialize an empty linked list.
    struct Node* head1=NULL; 
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
    printf("%lld", multiplyTwoLists(head, head1));
    // Free the memory allocated for the linked list nodes.
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
