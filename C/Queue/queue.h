#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdio.h>
#include <stdlib.h>

struct node {
    int          pay_load;
    struct node  *next;
} ;

struct node *create_node(int value);

struct queue {
    struct node  *head;
    struct node  *tail;
    int size;
};

void queue_init();                    // init queue
void queue_clear();                   // clear the queue

void queue_enqueue(int new_pay_load); // push to queue
struct node *queue_dequeue();         // pop from queue

int get_queue_size();                 // amount of nodes 

#endif