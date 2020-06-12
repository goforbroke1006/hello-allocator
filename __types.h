//
// Created by goforbroke on 6/12/20.
//

#ifndef HELLO_ALLOCATOR___TYPES_H
#define HELLO_ALLOCATOR___TYPES_H

#include <string>

class TestModel {
private:
    std::string mName;
    int mAge;

public:
    TestModel() {}

    TestModel(const std::string &mName, int mAge) : mName(mName), mAge(mAge) {}

    const std::string &getName() const {
        return mName;
    }

    void setName(const std::string &name) {
        TestModel::mName = name;
    }

    int getAge() const {
        return mAge;
    }

    void setAge(const int &age) {
        TestModel::mAge = age;
    }
};

#endif //HELLO_ALLOCATOR___TYPES_H
