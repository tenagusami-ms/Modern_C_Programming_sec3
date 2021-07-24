//
// Created by ykanya on 2021/07/23.
//
#ifndef MODERN_C_PROGRAMMING_SEC3_STACK_H
#define MODERN_C_PROGRAMMING_SEC3_STACK_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C"{
#endif


typedef struct Validator {
    bool (*const validate)(struct Validator *pThis, int val);
} Validator;

typedef struct {
    Validator base;
    const int min;
    const int max;
} RangeValidator;

typedef struct {
    Validator base;
    int previousValue;
} PreviousValidator;

typedef struct {
    int top;
    const size_t size;
    int *const pBuf;
    Validator *const pValidator;
} Stack;

bool validateRange(Validator *p, int val);
bool validatePrevious(Validator *p, int val);

bool push(Stack *, int);

bool pop(Stack *, int *);

#define newStack(buf) {0, sizeof(buf) / sizeof(int), (buf), NULL}

#define newRangeValidator(min, max) \
{{validateRange}, (min), (max)}

#define newPreviousValidator {validatePrevious, 0}

#define newStackWithValidator(buf, pValidator) { 0, sizeof (buf) / sizeof(int), (buf), pValidator}

#ifdef __cpluseplus
}
#endif

#endif //MODERN_C_PROGRAMMING_SEC3_STACK_H
