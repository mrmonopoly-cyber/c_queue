#include "c_queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOT_IMPLMENTED perror("not implemented")

struct c_queue{
    c_queue* next;
    uint16_t ele_size;
    uint8_t data[];
};

static uint8_t check_input_pointer(const void* ptr, const char* ptr_name){
    if (!ptr) {
        fprintf(stderr, "ERROR: NULL pointer %s\n", ptr_name);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

//public
uint8_t 
c_queue_push(c_queue** queue, const void* ele, const uint16_t ele_size)
{
    if (check_input_pointer(queue, "c_queue root pointer")) return EXIT_FAILURE;
    if (check_input_pointer(ele, "c_queue element to push")) return EXIT_FAILURE;
    if (!ele_size){
        fprintf(stderr, "ERROR: invalid data size, must be > 0"); 
        return EXIT_FAILURE;
    }

    if (!(*queue)) {
        *queue = calloc(1, sizeof(**queue) + ele_size);
        if (check_input_pointer(*queue, "c_queue new c_queue")) return EXIT_FAILURE;
        memcpy(&(*queue)->data[0], ele, ele_size);
        (*queue)->next=NULL;
        (*queue)->ele_size=ele_size;
        return EXIT_SUCCESS;
    }
    return c_queue_push(&(*queue)->next, ele, ele_size);
}

uint8_t 
c_queue_pop(c_queue** queue, void** out)
{
    if (check_input_pointer(queue, "c_queue root pointer")) return EXIT_FAILURE;
    if (check_input_pointer(out, "out root pointer")) return EXIT_FAILURE;
    if (check_input_pointer(*queue, "c_queue is empty")) return EXIT_FAILURE;

    if (!(*out)) {
        (*out) = calloc(1, (*queue)->ele_size);
        if (check_input_pointer(*out, "c_queue new out buffer")) return EXIT_FAILURE;
    }

    void* data = &(*queue)->data[0];

    memcpy(*out, data, (*queue)->ele_size);

    c_queue* temp = *queue;
    *queue = (*queue)->next;
    free(temp);

    return EXIT_SUCCESS;
}

uint8_t 
c_queue_is_empty(const c_queue* queue)
{
    return !queue;
}

void c_queue_free(c_queue* queue)
{
    if (check_input_pointer(queue, "c_queue root pointer")) return ;
    c_queue* temp = queue->next;

    free(queue);

    if (temp){
        return c_queue_free(temp);
    }
}
