#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int          pay_load;
    struct node  *next;
} node_t;

node_t *create_node(int value);

typedef struct {
    node_t  *head;
    node_t  *tail;
    int 	size;
} queue_t;

void queue_init();                    // init queue
void queue_clear();                   // clear the queue

void queue_enqueue(int new_pay_load); // push to queue
node_t *queue_dequeue();         	  // pop from queue

int get_queue_size();                 // amount of nodes 
void queue_print();

#endif
