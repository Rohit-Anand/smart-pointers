//
//  SmartPointers.cpp
//  Learning_cpp
//
//  Created by Rohit Anand on 19/07/18.
//  Copyright © 2018 Rohit Anand. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <functional>

/*
 As this is for demo, creating a factory so that later implementation
 can be added and further extended, without touching the main function
 */

//class SmartPointer {
//public:
//    virtual void run() = 0;
//};

// This class should be a singleton class
class Demo {
    // single name for one implementation
    std::map<std::string, std::function<void()>> spContainer;
    Demo() {}
public:
    static Demo& getInstance() {
        static Demo instance;
        return instance;
    }
    
    // This register should have a create object function of sp classes, if asked by user, create object
    void registerSP(std::string name, std::function<void()> sp) {
        spContainer.insert(std::make_pair(name, sp));
    }
    
    void listSPs() {
        std::cout << "Listing demoable SPs:" << std::endl;
        for(auto it : spContainer) {
            std::cout << "    " << it.first << std::endl;
        }
    }

    void showDemoOf(std::string name) {
        if (spContainer.find(name) != spContainer.end()) {
            spContainer[name]();
        } else {
            std::cout << "Invalid Entry" << std::endl;
        }
    }
};

class samplePointerClass {
    samplePointerClass() {}
public:
    static void run() {
        std::cout << "Sample Running Demo for pointer" << std::endl;
    }
    
    static bool registerF() {
        Demo::getInstance().registerSP("Sample", &(samplePointerClass::run));
        return true;
    }
    
    static bool initialize;
};

bool samplePointerClass::initialize = samplePointerClass::registerF();


class unique_ptr {
    unique_ptr() {}
public:
    static void run() {
        std::cout << "unique_ptr Running Demo for unique_ptr" << std::endl;
    }
    
    static bool registerF() {
        Demo::getInstance().registerSP("unique_ptr", &(unique_ptr::run));
        return true;
    }
    
    static bool initialize;
};

bool unique_ptr::initialize = unique_ptr::registerF();

int main() {
    Demo::getInstance().listSPs();
    Demo::getInstance().showDemoOf("Sample");
    Demo::getInstance().showDemoOf("unique_ptr");
    return 0;
}
