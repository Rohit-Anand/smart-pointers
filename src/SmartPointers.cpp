//
//  SmartPointers.cpp
//
//  Created by Rohit Anand on 06/June/2021.
//  Copyright © 2021 Rohit Anand. All rights reserved.
//

#include "UniquePtr.h"

#include <iostream>
#include <utility>

class SampleToTest {
    int m1;
    SampleToTest() { m1 = -1; }
public:
    SampleToTest(int i) : m1(i) {
        std::cout << "Sample Ctor: Creation" << std::endl;
    }

    ~SampleToTest() {
        std::cout << "Sample Dtor: Deletion" << std::endl;
    }

    void Print() {
        std::cout << "Printing SampleToTest State: " << m1 << std::endl;
    }
};

void CatchPointerTest(UniquePtr<SampleToTest> catchObj) {
    std::cout << "ABLE TO CATCH" << std::endl;
    catchObj->Print();
    return;
}

int main() {
    UniquePtr<SampleToTest> up(new SampleToTest(10));
    up->Print();
    up.get()->Print();
    // CatchPointerTest(up); --> Must Give Compilation Error
    // UniquePtr<SampleToTest> up2 = up; --> Must Give Compilation Error
    CatchPointerTest(std::move(up));

    // SampleToTest* up2 = up.get(); // This is a weak Pointer

   // TODO: Handle below case in further releases, using std::tuple
   // UniquePtr<SampleToTest> up2 = up.get();

    std::cout << "PTR is deleted already?" << std::endl;

    return 0;
}