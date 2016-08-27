#include "queue.h"

int main(int argc, char const *argv[])
{
    int i;

    queue_init();

    for (i = 0; i < 10; i++) {
        int *new_value = (int *)malloc(sizeof(int));
        if (new_value) {
            *new_value = i;
            queue_enqueue((void *)new_value);
        }
    }

    queue_print();

    printf("size = %d\n", get_queue_size());

    void *ptr = queue_dequeue();
    
    printf("\t\tptr = %d\n", *((int *)ptr));
    
    free(ptr);

    queue_print();

    printf("size = %d\n", get_queue_size());

    queue_clear();

    printf("size = %d\n", get_queue_size());
    return 0;
}
