#include "queue.h"

struct queue test_queue;

struct node *create_node(int value)
{
    struct node *new_node = NULL;

    new_node = (struct node *)malloc(sizeof(struct node));
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
        struct node *node = queue_dequeue();
        free(node);
    }

    queue_init();
}

void queue_enqueue(int new_pay_load)
{
    struct node *old_tail = test_queue.tail;
    struct node *new_node = NULL;

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
    struct node *dequeue_node = NULL;
    struct node *new_head = NULL;

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
    struct node *ptr = test_queue.head;

    printf("\n");

    while(ptr) {
        printf("\tnode = %d\n", ptr->pay_load);
        ptr = ptr->next;
    }
    
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int i;

    queue_init();

    for (i = 0; i < 10; i++) {
        queue_enqueue(i);
    }

    queue_print();

    printf("size = %d\n", get_queue_size());

    struct node *ptr = queue_dequeue();

    free(ptr);

    queue_print();

    printf("size = %d\n", get_queue_size());

    queue_clear();

    printf("size = %d\n", get_queue_size());
    return 0;
}