/**
 * This method of subclassing ins C uses member function pointers to 
 * implement sub-classing methods 
 */

 #ifndef QUEUE_H
 #define QUEUE_H

 #define QUEUE_SIZE 10 

 /* class Queue */
 typedef struct Queue Queue;
 struct Queue {
    int buffer[QUEUE_SIZE]; /* where data things are */
    int head;
    int size;
    int tail;
    int(*isFull)(Queue* const me);
    int(*isEmpty)(Queue* const me);
    int(*getSize)(Queue* const me);
    void(*insert)(Queue* const me, int k);
    int(*remove)(Queue* const me);
 };

 /* constructors and desctructors */
 void Queue_init(Queue* const me, 
    int(*isFullFunction)(Queue* const me),
    int(*isEmptyFunction)(Queue* const me),
    void(*insertFunction)(Queue* const me),
    int(*removeFunction)(Queue* const me)
);

void Queue_cleanup(Queue* const me);

/* operations */
int Queue_isFull(Queue* const me);
int Queue_isEmpty(Queue* const me);
int Queue_getSize(Queue* const me);
void Queue_insert(Queue* const me, int k);

Queue* Queue_create(void);
void Queue_destroy(Queue* const me);

#endif