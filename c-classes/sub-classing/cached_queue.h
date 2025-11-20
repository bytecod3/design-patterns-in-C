/**
 * 
 * cached queue header file
 * This file declares a header file that defines cached queue parameters
 * 
 * 
 * Cached Queue maintains 2 queues: on an input the other an output 
 * 
 */

#ifndef CACHED_QUEUE_H
#define CACHED_QUEUE_H

#include "queue.h" /* base class */
typedef struct CachedQueue CachedQueue;

struct CachedQueue {
    Queue* queue; /* base class */

    /* new attributes */
    char filename[80];

    int numberElementsOnDisk;

    /* aggregation in subclass */
    Queue* outputQueue;
    
    /* inherited virtual functions */
    int (*isFullfunction)(CachedQueue *const me);
    int (*isEmptyfunction)(CachedQueue *const me);
    int (*getSizefunction)(CachedQueue *const me);
    void (*insertfunction)(CachedQueue *const me, int k);
    int (*removefunction)(CachedQueue *const me);

    /* new virtual functions */
    void (*flush)(CachedQueue *const me);
    void (*load)(CachedQueue *const me);
};  


/* constructors and destructors */
void CachedQueue_init(
    CachedQueue *const me,
    char *fname,
    int (*isFullfunction)(CachedQueue *const me),
    int (*isEmptyfunction)(CachedQueue *const me),
    int (*getSizefunction)(CachedQueue *const me),
    void (*insertfunction)(CachedQueue *const me, int k),
    int (*removefunction)(CachedQueue *const me),

    /* new virtual functions */
    void (*flush)(CachedQueue *const me),
    void (*load)(CachedQueue *const me)
);

void CachedQueue_cleanup(CachedQueue* const me);

/* operations */
int CachedQueue_isfull(CachedQueue *const me);
int CachedQueue_isempty(CachedQueue *const me);
int CachedQueue_getsize(CachedQueue *const me);
void CachedQueue_insert(CachedQueue *const me, int k);
int CachedQueue_remove(CachedQueue *const me);

/* new virtual functions */
void CachedQueue_flush(CachedQueue *const me);
void CachedQueue_load(CachedQueue *const me);

CachedQueue* CachedQueue_create(void);
void CachedQueue_destroy(CachedQueue* const me);

#endif