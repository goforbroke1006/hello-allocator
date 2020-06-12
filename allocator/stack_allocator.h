//
// Created by goforbroke on 6/12/20.
//

#ifndef HELLO_ALLOCATOR_STACK_ALLOCATOR_H
#define HELLO_ALLOCATOR_STACK_ALLOCATOR_H

#include "__basic.h"

class StackAllocator : public BasicAllocator {
public:
    StackAllocator(
            void *startAddr,
            unsigned long totalSize
    )
            : BasicAllocator(startAddr, totalSize) {}

    uint8_t *beforeEnter() {
        return this->mCurrAddr;
    }

    void afterExit(uint8_t *ptr) {
        this->mCurrAddr = ptr;
    }
};

#endif //HELLO_ALLOCATOR_STACK_ALLOCATOR_H
