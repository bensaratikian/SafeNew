//
//  main.cpp
//
//  Created by Ben Saratikian on 6/18/19.
//  Copyright © 2019 Ben Saratikian. All rights reserved.
//

#include <iostream>
#include "SafeNew.h"
#include <memory>

struct A {
    A() {
        std::cout << "Ctor\n";
    }
    
    ~A() {
        std::cout << "Dtor\n";
    }
};

int main() {
    SafeNew<A> _new;
    SafeNew<int> _new1;
    A* a = _new(A());
    int* i = _new1(12);
    return 0;
}
