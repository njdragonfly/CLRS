/*
 * FILE     : blockqueue.c
 * Author   : Tetsu Soh
 * NOTES    : Implementation of block queue based on queue.c.
 */

#include "blockqueue.h"
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

struct block_queue_tag {
    c_queue *queue;
    pthread_mutex_t lock;
    pthread_cond_t notEmpty;
    pthread_cond_t notFull;
    pthread_cond_t isEmpty;
};

block_queue *
init_block_queue(unsigned int s)
{
    c_queue *q = init_queue(s);
    return init_block_queue_with(q);
}

block_queue *
init_block_queue_with(c_queue *q)
{
    block_queue *bq = (block_queue *)malloc(sizeof(block_queue));
    bq->queue = q;
    pthread_mutex_init(&(bq->lock), NULL);
    pthread_cond_init(&(bq->notEmpty), NULL);
    pthread_cond_init(&(bq->notFull), NULL);
    pthread_cond_init(&(bq->isEmpty), NULL);
    return bq;
}

void 
destroy_block_queue(block_queue *p)
{
    pthread_mutex_destroy(&(p->lock));
    pthread_cond_destroy(&(p->notEmpty));
    pthread_cond_destroy(&(p->notFull));
    destroy_queue(p->queue);
    free(p);
}

void 
block_enqueue(block_queue *q, queue_data_t item)
{
    pthread_mutex_lock(&(q->lock));
    /* check overflow */
    if(is_full(q->queue)) {
        /*perror("overflow\n");*/
        pthread_cond_wait(&(q->notFull), &(q->lock));
    }

    insert(q->queue, item); 
    pthread_cond_signal(&(q->notEmpty));

    pthread_mutex_unlock(&(q->lock));
}

queue_data_t 
block_dequeue(block_queue *q)
{
    queue_data_t val;
    pthread_mutex_lock(&(q->lock));
    /* check underflow */
    if(is_empty(q->queue)) {
        /*perror("underflow\n");*/
        pthread_cond_signal(&(q->isEmpty));
        pthread_cond_wait(&(q->notEmpty), &(q->lock));
    } 

    val = extract(q->queue);
    pthread_cond_signal(&(q->notFull));

    pthread_mutex_unlock(&(q->lock));

    return val;
}

void
block_until_empty(block_queue *q)
{
    pthread_mutex_lock(&(q->lock));
    if(!is_empty(q->queue)) {
        pthread_cond_wait(&(q->isEmpty), &(q->lock)); 
    }
    pthread_mutex_unlock(&(q->lock));
}
