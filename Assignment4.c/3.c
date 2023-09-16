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
void findNthFromEnd(struct Node* head, int n) {
    if (head == NULL || n <= 0) {
        return ;
    }

    struct Node* firstPointer = head;
    struct Node* secondPointer = head;

    // Move the first pointer n nodes ahead
    for (int i = 0; i < n; i++) {
        if (firstPointer == NULL) {
            return ; // The list is shorter than n nodes
        }
        firstPointer = firstPointer->next;
    }

    // Move both pointers until the first pointer reaches the end
    while (firstPointer != NULL) {
        firstPointer = firstPointer->next;
        secondPointer = secondPointer->next;
    }
    printf("Element at %dth node from end is %d\n",n,secondPointer->data);
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
    printf("enter the position from end\n");
    int n; scanf("%d",&n);
    findNthFromEnd(head,n);
    // Free the memory allocated for the linked list nodes.
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
