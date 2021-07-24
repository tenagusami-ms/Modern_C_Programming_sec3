#include <stdio.h>
#include "stack.h"

int main() {
    int buf1[16] = {0};

    //RangeValidator range = {0, 9};
    //RangeValidator validator = newRangeValidator(0, 9);
    //PreviousValidator previousValue = {2};
    PreviousValidator validator = newPreviousValidator;

    Stack s = newStackWithValidator(buf1, &validator.base);
    if (push(&s, 1)) {
        int popped = 0;
        if (pop(&s, &popped)) {
            printf("pop successful with popped value %d\n", popped);
        } else {
            printf("pop failed\n");
        }
    }else{
        printf("push failed\n");
    }

    return 0;
}
