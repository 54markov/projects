#include "queue.h"

queue_t test_queue;

node_t *create_node(int value)
{
    node_t *new_node = NULL;

    new_node = (node_t *)malloc(sizeof(node_t));
    if (!new_node) {
        fprintf(stderr, "ERROR, can't allocate memory for new node\n");
        return NULL;
    }

    new_node->pay_load = value;
    new_node->next = NULL;

    return new_node;
}

void queue_init()
{
    test_queue.size  = 0;
    test_queue.head = NULL;
    test_queue.tail = NULL;
}

void queue_clear()
{
    while(test_queue.size > 0) {
        node_t *node = queue_dequeue();
        free(node);
    }

    queue_init();
}

void queue_enqueue(int new_pay_load)
{
    node_t *old_tail = test_queue.tail;
    node_t *new_node = NULL;

    new_node = create_node(new_pay_load);
    if (new_node == NULL) {
        return;
    } else {
        test_queue.tail = new_node;
    }

    if (test_queue.head == NULL) {
        test_queue.head = test_queue.tail;
    } else {
        old_tail->next = test_queue.tail;
    }

    test_queue.size += 1;
}

struct node *queue_dequeue()
{
    node_t *dequeue_node = NULL;
    node_t *new_head = NULL;

    if (test_queue.size == 0) {
        fprintf(stderr, "ERROR: can't dequeue, queue is empty\n");
        return NULL;
    }

    /* Pop first node */
    dequeue_node = test_queue.head;

    new_head = test_queue.head->next;
    test_queue.head = new_head;
    test_queue.size -= 1;
    
    return dequeue_node;
}

int get_queue_size()
{
    return test_queue.size;
}

void queue_print()
{
    node_t *ptr = test_queue.head;

    printf("\n");

    while(ptr) {
        printf("\tnode = %d\n", ptr->pay_load);
        ptr = ptr->next;
    }
    
    printf("\n");
}
