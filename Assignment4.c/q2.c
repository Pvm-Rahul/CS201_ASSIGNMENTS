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
void reverseBetween(struct Node* head, int m, int n) {
    if (head == NULL || m >= n) {
        return ;
    }

    struct Node* dummy = (struct Node*)malloc(sizeof(struct Node));
    dummy->next = head;
    struct Node* preM = dummy; // Node before the mth node
    struct Node* nodeM, *nodeN; // mth and nth nodes
    struct Node* postN; // Node after the nth node

    // Traverse to find preM and nodeM
    for (int i = 1; i < m; i++) {
        preM = preM->next;
    }
    nodeM = preM->next;
// Traverse to find nodeN and postN
    for (int i = m; i < n; i++) {
        preM->next = nodeM->next; // Remove nodeM from its position
        nodeN = nodeM->next;
        nodeM->next = nodeN->next; // Insert nodeN after preM
        nodeN->next = preM->next;
        preM->next = nodeN;
    }
    struct Node* newHead = dummy->next;
    free(dummy);
    printf("the final list is\n");
    displayList(newHead);
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
    int m,n; 
    printf("Enther the positons to shift/n");
    scanf("%d %d",&m,&n);
    reverseBetween(head,m,n);
    // Free the memory allocated for the linked list nodes.
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
