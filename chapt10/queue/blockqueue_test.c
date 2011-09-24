/*
 * FILE     : blockqueue_test.c
 * Author   : Tetsu Soh
 * NOTES    : The test appliation for block queue.
 */
#include <pthread.h>
#include <stdio.h>
#include "blockqueue.h"

struct thread_data {
    block_queue *q;
    int size;
};

static void *
generate_numbers(void *data)
{
    int i;
    struct thread_data *d = (struct thread_data *)data;

    for(i = 0; i < d->size; i++) {
        block_enqueue(d->q, i);
        printf("generate: %d\n", i);
    }
}

static void *
print_numbers(void *data)
{
    int i;
    struct thread_data *d = (struct thread_data *)data;

    for(i = 0; i < d->size; i++) {
        queue_data_t v = block_dequeue(d->q);
        printf("consume: %d\n", (int)v);
    }
}

int
main(void)
{
    pthread_t pt, ct;
    struct thread_data data;
    data.q = init_block_queue(5);
    data.size = 10;

    pthread_create(&pt, NULL, generate_numbers, (void *)&data);
    pthread_create(&ct, NULL, print_numbers, (void *)&data);

    pthread_exit(NULL);
}
