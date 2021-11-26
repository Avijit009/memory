#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
   size_t mem_size = 1024 * 1024 * 1024;
    printf("MEMSIZE: %lu\n", mem_size);
    //printf("SIZE OF: void*:%lu\n", sizeof(void*));
    //printf("SIZE OF: char*:%lu\n", sizeof(char*));
    void *based = malloc(mem_size);  //mem_size = 1024^3
    int stage = 65536;
    int initialized = 0;
    if (based) {
        printf("Allocated %zu Bytes from %p to %p\n", mem_size, based, based + mem_size);
    } else {
        printf("Error in allocation.\n");
        return 1;
    }
    int n = 0;
    while (initialized < mem_size) {  //initialize it in batches
        //printf("%6d %p-%p\n", n, based+initialized, based+initialized+stage);
        n++;
        memset((char *)based + initialized, '$', stage);
        initialized += stage;
    }

    //free(based);
    
    while (1)
    {
        printf("%d", n);
        n++;
    }

    return 0;
}
