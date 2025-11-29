#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* #Doubly Linked List
[Previous_Addr]Data[Next_Addr]<-->[Previous_Addr]Data[Next_Addr]<-->[Previous_Addr]Data[Next_Addr]<<>>NULL
## Try with circular too

Create_Node() --> Create Node in memory --> add or attach node will link the nodes together.

--> You call --> add_node() --> inside add_node there will be create_node function. 
--> add_node will be the common API that will just take data to be added into the Linked List.
--> Making only add_node to expose to outer world and keeping create_node() and other upcoming functions as it is untouched.
*/

#define CLR_GREEN  "\x1b[32m"
#define CLR_RESET  "\x1b[0m"

#define DBG(fmt, ...) \
    printf(CLR_GREEN "[DBG] " CLR_RESET fmt "\n", ##__VA_ARGS__)

struct Node {
    int data;
    struct Node *prev;
    struct Node *nxt;
};

/* Temporary GLOBAL Head pointer for traversing */
struct Node *g_Head_ptr = NULL;

struct Node * create_node(int data_cpy, struct Node *ptr_node)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Malloc failed - 0\r\n");
        return NULL;
    }
    new_node->data = data_cpy;
    new_node->nxt = NULL;

    if (ptr_node == NULL) {
        /* This is the first node creation happening. 
           First Node will have prev_addr as NULL.
        */
        new_node->prev = NULL;
        g_Head_ptr = new_node;
    } else {
        /* This is not the first node, previous ptr will be populated in *ptr_node from argument */
        ptr_node->nxt = new_node;
        new_node->prev = ptr_node;
    }
    
    return new_node;
}

void add_node(int data_cpy)
{
    /*Check in here if first node, head node kind of checks*/
    /* Also keep this add_node generic for Singly, doubly*/
    static struct Node *last_created;

    if (g_Head_ptr == NULL) {
        last_created = g_Head_ptr;
    }
    //DBG_HEX(last_created);
    last_created = create_node(data_cpy, last_created);
}

void display(void)
{
    struct Node *temp = g_Head_ptr;
    while (temp != NULL) {
        DBG("Data : %d", temp->data);
        temp = temp->nxt;
    }
}

void free_nodes(void)
{
    struct Node *temp = g_Head_ptr;
    struct Node *next_ptr;

    while (temp != NULL) {
        next_ptr = temp->nxt;
        free(temp);
        temp = next_ptr;
    }
    g_Head_ptr = NULL;
}

int main(void)
{
    int data[] = {10,20,30,40};

    for (size_t i = 0; i < sizeof(data)/sizeof(data[0]); i++) {
        add_node(data[i]);
    }
    
    display();
    free_nodes();
    display();

    return 0;
}