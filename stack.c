
//
// Created by ykanya on 2021/07/23.
//
#include <stdbool.h>
#include <stdio.h>
#include "stack.h"


static bool isStackFull(const Stack *p){
    return p->top == p->size;
}

static bool isStackEmpty(const Stack *p){
    return p->top == 0;
}

bool validate(Validator *p, int val){
    if (! p) {return true;}
    return p->validate(p, val);
}

bool push(Stack * p, int val){
    if ( ! validate(p->pValidator, val) || isStackFull(p)) {return false;}
    p->pBuf[p->top++] = val;
    return true;
}

bool pop(Stack *p, int *pRet){
    if (isStackEmpty(p)) {return false;}
    *pRet = p->pBuf[--p->top];
    return true;
}

bool validateRange(Validator *p, int val) {
    RangeValidator *pThis = (RangeValidator *) p;
    return pThis->min <= val && val <= pThis->max;
}

bool validatePrevious(Validator *p, int val) {
    PreviousValidator *pThis = (PreviousValidator *) p;
    if (val < pThis->previousValue) { return false; }
    pThis->previousValue = val;
    return true;
}
