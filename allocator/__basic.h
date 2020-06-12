//
// Created by goforbroke on 6/12/20.
//

#ifndef HELLO_ALLOCATOR___BASIC_H
#define HELLO_ALLOCATOR___BASIC_H

#include <cstdint>
#include <cstdlib>
#include <stdexcept>

#include "__consts.h"

class BasicAllocator {
public:
    /**
     * Constructor prepare to work with memory that was allocated outside this allocator
     * @param startAddr
     * @param totalSize
     */
    explicit BasicAllocator(void *startAddr, uint64 totalSize) : mTotalSize(totalSize) {
        this->mStartAddr = static_cast<uint8_t *>(startAddr);
        this->mCurrAddr = static_cast<uint8_t *>(startAddr);
        this->mTotalSize = totalSize;
    }

    template<typename T>
    T *New(T obj) {
        uint64 s = sizeof(obj);
        if (*this->mCurrAddr + s > this->mTotalSize) {
            throw std::runtime_error("stack overflow");
        }

        T *ptr = (T *) this->mCurrAddr;
        *ptr = obj;

        this->mCurrAddr += s;

        return ptr;
    }

    uint64 getFreeMemory() {
        uint64 used = this->mCurrAddr - this->mStartAddr;
        return this->mTotalSize - used;
    }

    virtual ~BasicAllocator() {
        free(this->mStartAddr);
    }

protected:
    template<typename T>
    T *__new(T obj) {

    }

    uint8_t *mStartAddr;
    uint8_t *mCurrAddr;
    uint64 mTotalSize;

};

#endif //HELLO_ALLOCATOR___BASIC_H
