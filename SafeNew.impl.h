//
//  SafeNew.impl.h
//
//  Created by Ben Saratikian on 6/20/19.
//  Copyright © 2019 Ben Saratikian. All rights reserved.
//

#ifndef SafeNew_impl_h
#define SafeNew_impl_h

template<typename T>
T* SafeNew<T>::operator()(T&& arg) {
    std::lock_guard<std::mutex> lock(_m);
    T* ptr = new T(std::forward<T&&>(arg));
    _stack.emplace(ptr);
    return ptr;
}

template<typename T>
SafeNew<T>::~SafeNew() {
    while(_stack.size()) {
        delete _stack.top();
        _stack.pop();
    }
}

#endif /* SafeNew_impl_h */
