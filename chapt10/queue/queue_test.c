/*
 * FILE     : queue_test.c
 * Author   : Tetsu Soh
 * NOTES    : Test code for the queue implementation.
 */

#include "queue.h"
#include <stdio.h>

int
main(void)
{
    int i, r;
    c_queue *q = init_queue(5);
    int items[] = {1,2,3,4,5,6};

    for(i = 0; i < 5; i++) {
        enqueue(q, (queue_data_t)&items[i]);
    }
    r = enqueue(q, (queue_data_t)&items[5]);
    if(r != 1) {
        return 1;
    }

    for(i = 0; i < 3; i++) {
        r = *((int *)dequeue(q));
        printf("item=%d\n", r);
    }

    for(i = 0; i < 3; i++) {
        enqueue(q, (queue_data_t)&items[i]);
    }
    r = enqueue(q, (queue_data_t)&items[5]);
    if(r != 1) {
        return 1;
    }

    destroy_queue(q);

    return 0;
}
