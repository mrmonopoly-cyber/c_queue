#include "../c_queue.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    c_queue* q = NULL;
    int a =5;
    int b =6;

    printf("input: %d\n",a);

    c_queue_push(&q,&a,sizeof(a));
    c_queue_push(&q,&b,sizeof(b));

    void* aq = NULL;

    c_queue_pop(&q, &aq);
    printf("input: %d\n",*(int *)aq);
    free(aq);
    aq=NULL;

    c_queue_pop(&q, &aq);
    printf("input: %d\n",*(int *)aq);
    free(aq);
    aq=NULL;

    if (c_queue_is_empty(q)) {
        printf("Empty\n");
    }else {
        printf("NOT Empty\n");
    }

    c_queue_free(q);
    return EXIT_SUCCESS;
}
