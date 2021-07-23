#include <stdio.h>
#include "stack.h"

int main() {
    printf("Hello, World!\n");

    if (push(1)) {
        int *popped = NULL;
        if (pop(popped)) {
            printf("%d", *popped);
        } else {
            printf("failed");
        }
    }

    return 0;
}
