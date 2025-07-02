#include <stdio.h>

/* a pointer to an incomplete type hides the implementation details */
typedef struct Customer* CustomerPtr;

CustomerPtr createCustomer(const char* name);
void destroyCustomer(CustomerPtr customer);