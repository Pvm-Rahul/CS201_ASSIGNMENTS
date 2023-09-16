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
struct Node* reverseKNodes(struct Node* head, int k) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    int count = 0;

    while (count < k && current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if (current != NULL) {
        head->next = current;
    }

    count = 0;
    while (count < k - 1 && current != NULL) {
        current = current->next;
        count++;
    }

    if (current != NULL) {
        current->next = reverseKNodes(current->next, k);
    }

    return prev;
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
    int k;
    printf("enter the value of k for alter k nodes\n"); scanf("%d",&k);
     head = reverseKNodes(head, k);
    printf("Linked list after reversing every alternate %d nodes: ", k);
    displayList(head);
    // Free the memory allocated for the linked list nodes.
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
