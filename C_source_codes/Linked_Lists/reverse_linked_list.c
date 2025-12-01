#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct Node {
    int32_t data;
    struct Node* next;
} Node;

/**
 * Creates a node. 
 * Returns NULL if malloc fails.
 */
Node* create_node(int32_t data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        // Handle error: in embedded, this might trigger a system reset or error log
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

/**
 * Appends data to the end of the list.
 * CRITICAL: Returns the (possibly new) head of the list.
 */
Node* append(Node* head, int32_t data) {
    Node* new_node = create_node(data);
    if (new_node == NULL) return head; // Fail safe, return original list untouched

    // Case 1: List is empty. New node becomes the head.
    if (head == NULL) {
        return new_node;
    }

    // Case 2: List exists. Traverse to tail.
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    // Link the new node
    current->next = new_node;

    // Return the original head unchanged
    return head;
}

void print_list(Node* head) {
    Node* current = head;
    printf("List: ");
    while (current != NULL) {
        printf("[%d] -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

/**
 * Frees memory.
 * NOTE: Cannot set main's 'head' to NULL automatically without double pointer.
 */
void free_list(Node* head) {
    Node* tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void reverse_list(Node *head)
{
    /* head --> 10 --> 20 --> 30 --> NULL
       head --> 30 -->20-->10-->NULL

       current-#20000 next-#40000
    */
   Node *tmp = head;
   Node *nxt = tmp->next;

   while (tmp != NULL) { 
   }
   
}

int main(void) {
    Node* head = NULL; // Start empty

    // Usage pattern: Must assign result back to head
    head = append(head, 10);
    head = append(head, 20);
    head = append(head, 30);

    print_list(head);
    reverse_list(head);

    free_list(head);
    head = NULL; // Manual protection against dangling pointer

    return 0;
}