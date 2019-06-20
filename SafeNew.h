//
//  SafeNew.hpp
//
//  Created by Ben Saratikian on 6/19/19.
//  Copyright © 2019 Ben Saratikian. All rights reserved.
//

#ifndef SafeNew_h
#define SafeNew_h

#include <stdio.h>
#include <stack>
#include <vector>
#include <mutex>

template<typename T>
class SafeNew final {
public:
   //Default constructor lockes mutex to make class thread-safe
    SafeNew() = default;
    
    //Copy and Move constructors are deleted
    SafeNew(const SafeNew& other) = delete;
    SafeNew(SafeNew&& other) = delete;
    
    //Copy and Move assignment operators are deleted
    SafeNew& operator=(const SafeNew& other) = delete;
    SafeNew& operator=(SafeNew&& other) = delete;
    
    //Overloaded operator() is used for main functionality
    T* operator()(T&& arg);
    
    //Destructor of the class deallocates the used memory
    ~SafeNew();
private:
    std::stack<const T*, std::vector<const T*>> _stack;
    std::mutex _m;
};
#include "SafeNew.impl.h"
#endif /* SafeNew_hpp */
