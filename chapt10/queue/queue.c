/*
 * FILE     : queue.c
 * Author   : Tetsu Soh
 * NOTES    : Implement queue.
 */

#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

struct queue_tag {
    queue_data_t *items;
    int tail;
    int head;
    int size;
    int count;
};

static int
inc(c_queue *q, int s)
{
    return (++s == q->size) ? 0 : s;
}

void 
insert(c_queue *q, queue_data_t item)
{
    q->items[q->tail] = item;
    q->tail = inc(q, q->tail);
    q->count++;
}

queue_data_t
extract(c_queue *q)
{
    queue_data_t item = q->items[q->head];
    q->head = inc(q, q->head);
    q->count--;

    return item;
}

c_queue *
init_queue(size_t size)
{
    c_queue *q = (c_queue *)malloc(sizeof(c_queue));
    q->items = (queue_data_t *)malloc(sizeof(queue_data_t) * size);
    q->size = size;
    q->tail = q->head = q->count = 0;
    return q;
}

int
is_full(c_queue *q)
{
    return (q->count == q->size);
}

int
is_empty(c_queue *q)
{
    return (q->count == 0);
}

int
enqueue(c_queue *q, queue_data_t item)
{
    /* check overflow */
    if(is_full(q)) {
        perror("overflow\n");
        return 1;
    }

    insert(q, item);

    return 0;
}

queue_data_t
dequeue(c_queue *q)
{
    /* check underflow */
    if(is_empty(q)) {
        perror("underflow\n");
        return (queue_data_t)0;
    } 

    return extract(q);
}

void
destroy_queue(c_queue *q)
{
    free(q->items);
    free(q);
}
