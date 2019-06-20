# SafeNew
SafeNew is wrapper class of **__new__**, and was built based on RAII principle.
You can use **C**'s raw pointers without worrying about memory leaks.

**This is an example of using the ___new__ object, which is exception-safe and also thread-safe**
```C++
int main() {
    SafeNew<A> _new;
    SafeNew<int> _new1;
    A* a = _new(A());
    int* i = _new1(12);
    return 0;
}
```
