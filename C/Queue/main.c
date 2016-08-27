#include "queue.h"

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
