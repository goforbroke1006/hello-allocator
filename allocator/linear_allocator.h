//
// Created by goforbroke on 6/11/20.
//

#ifndef HELLO_ALLOCATOR_LINEAR_ALLOCATOR_H
#define HELLO_ALLOCATOR_LINEAR_ALLOCATOR_H

#include <stdexcept>

#include "__basic.h"

class LinearAllocator : public BasicAllocator {
public:
    LinearAllocator(void *startAddr, unsigned long totalSize) : BasicAllocator(startAddr, totalSize) {}

private:
    void init(uint64 totalSize) {
        void *ptrVoid = malloc(totalSize);
        auto *ptrSpec = static_cast<uint8_t *>(ptrVoid);
        this->mStartAddr = ptrSpec;
        this->mCurrAddr = ptrSpec;
        this->mTotalSize = totalSize;
    }

};

#endif //HELLO_ALLOCATOR_LINEAR_ALLOCATOR_H
