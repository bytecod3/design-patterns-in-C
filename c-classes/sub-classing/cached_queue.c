/**
 * implements a cached queue that inherits from the base class 
 *
 */

 #include "cached_queue.h"
 #include <string.h>

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
    void (*flushfunction)(CachedQueue *const me),
    void (*loadfunction)(CachedQueue *const me)
) {

    /* initialize the base class */
    me->queue = Queue_create();

    /* initialize sub class attributes */
    me->numberElementsOnDisk = 0;
    strcpy(me->filename, fname);

    /* initialize aggregates */
    me->outputQueue = Queue_create();

    /* initialize subclass virtual operations ptrs */
    me->isFullfunction = isFullfunction;
    me->isEmptyfunction = isEmptyfunction;
    me->getSizefunction = getSizefunction;
    me->insertfunction = insertfunction;
    me->removefunction = removefunction;
    me->flush = flushfunction;
    me->load = loadfunction;
}

/* operation cleanup */
void CachedQueue_cleanup(CachedQueue* const me) {

}