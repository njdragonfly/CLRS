/*
 * FILE     : blockqueue.h
 * Author   : Tetsu Soh
 * NOTES    : define queue record structure and 
 *            all necessary forward declarations.
 */
#include "queue.h"

#ifndef _Block_Queue_h

    struct block_queue_tag;
    typedef struct block_queue_tag block_queue;

    /* create and initilized a block queue. */
    block_queue *init_block_queue(unsigned int s);
    /* create and initilized a block queue by wrapping a general queue. */
    block_queue *init_block_queue_with(c_queue *q);
    /* destroy the queue, all mutex lock and condition lock will be destory.*/
    void destroy_block_queue(block_queue *p);
    /* if queue is full, the enqueue action will be block until has space. */
    void block_enqueue(block_queue *q, queue_data_t item);
    /* if queue is empty, the dequeue action will be block until has element. */
    queue_data_t block_dequeue(block_queue *q);
	/* block the caller until the queue is empty. */
    void block_until_empty(block_queue *q);

#endif /* _Block_Queue_h */
