/*
 * FILE     : queue.h
 * Author   : Tetsu Soh
 * NOTES    : define queue record structure and 
 *            all necessary forward declarations.
 */
typedef unsigned long int queue_data_t;

#ifndef _Queue_h

    struct queue_tag;
    typedef struct queue_tag c_queue;
    /* create and initialize a new queue with given size. */
    c_queue *init_queue(unsigned int s);
    /* destroy the queue. */
    void destroy_queue(c_queue *p);
    /* enqueue without check overflow. */
    void insert(c_queue *q, queue_data_t item);
    /* dequeue without check underflow. */
    queue_data_t extract(c_queue *q);
    /* enqueue, return 1 if overflow, otherwise return 0. */
    int enqueue(c_queue *q, queue_data_t item);
    /* dequeue, return NULL if underflow. */
    queue_data_t dequeue(c_queue *q);

    int is_full(c_queue *q);
    int is_empty(c_queue *q);

#endif /* _Queue_h */
