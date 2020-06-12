#include <iostream>

#include "allocator/linear_allocator.h"
#include "__types.h"
#include "allocator/stack_allocator.h"

void linearDemo();

void stackDemo();

int main() {
//    linearDemo();
    stackDemo();

    return 0;
}

void linearDemo() {
    int size = 128 * 1024 * 1024;
    LinearAllocator la(malloc(size), size);

    TestModel *tm = la.New(TestModel("John Smith",30));

    std::cout << tm->getName() << ", " << tm->getAge() << " y.o." << std::endl;
}

void stackDemo() {
    int size = 128 * 1024 * 1024;
    StackAllocator sa(malloc(size), size);

    std::cout << "free (1) " << sa.getFreeMemory() << std::endl;

    TestModel *tm1 = sa.New(TestModel("root 1", 22));

    std::cout << "free (2) " << sa.getFreeMemory() << std::endl;

    uint8_t *memSpan = sa.beforeEnter();
    {
        TestModel *tm21 = sa.New(TestModel("inner 1", 10));
        TestModel *tm22 = sa.New(TestModel("inner 2", 10));
        TestModel *tm23 = sa.New(TestModel("inner 3", 10));
        std::cout << "free (3) " << sa.getFreeMemory() << std::endl;
    }
    sa.afterExit(memSpan);

    std::cout << "free (2) " << sa.getFreeMemory() << std::endl;

    TestModel *tm2 = sa.New(TestModel("root 2", 33));

    std::cout << tm1->getName() << ", " << tm1->getAge() << " y.o." << std::endl;
    std::cout << tm2->getName() << ", " << tm2->getAge() << " y.o." << std::endl;

    std::cout << "free (2) " << sa.getFreeMemory() << std::endl;
}
