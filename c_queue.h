#pragma once

#include <stdint.h>
typedef struct c_queue c_queue;


uint8_t c_queue_push(c_queue** queue, const void* ele, const uint16_t ele_size);
uint8_t c_queue_pop(c_queue** queue, void** out);
uint8_t c_queue_is_empty(const c_queue* queue);
void c_queue_free(c_queue* queue);
