#include <stdio.h>
#include "Customer.h"
#include <stdlib.h>

struct Customer{
    const char* name;
    int no_orders;
};

#define MAX_OBJECTS 10
static struct Customer objectPool[MAX_OBJECTS];
static size_t num_objects = 0;

CustomerPtr createCustomer(const char* name) {
    //CustomerPtr customer = malloc(sizeof * customer); 
    
    // for embedded, use static allocation 
    CustomerPtr customer = NULL;
    if(num_objects < MAX_OBJECTS) {
        customer = &objectPool[num_objects++];
        /* initialize the object */
    }
    

    if(customer) {
        /* initialize each field in the customer*/

    } 

    return customer;
}

void destroyCustomer(CustomerPtr customer) {
    free(customer);
}