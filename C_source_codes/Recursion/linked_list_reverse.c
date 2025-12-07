#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

void add_node_1(node_t **head, int value)
{
    node_t *new = malloc(sizeof(node_t));
    if (new == NULL) {
        printf("Malloc failed\n");
        return;
    }

    new->data = value;
    new->next = NULL;

    if (*head == NULL) {
        *head = new;
    } else {
        node_t *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new;
    }
}

void display(node_t *head)
{
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    node_t *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

node_t* reverse_recursive(node_t *head)
{
    if((head == NULL) || head->next == NULL) {
        return head;
    }

    node_t *new_head = reverse_recursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return new_head;
}

int main(void)
{
    node_t *head = NULL;
    int data[5] = {1,2,3,4,5};

    add_node_1(&head, data[1]);
    add_node_1(&head, data[3]);
    add_node_1(&head, data[0]);

    display(head);

    head = reverse_recursive(head);
    display(head);


    return 0;
}
