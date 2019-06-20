# SafeNew
SafeNew is wrapper class of **__new__**, and was built based on RAII principle.
You can use **C**'s raw pointers without worrying about memory leaks. 
**This is an example of using the ___new__ object, which is exception-safe and also thread-safe**
```C++
int main() {
    A* a = _new<A>(A());
    int* i = _new<int>(2);
    return 0;
}
```
