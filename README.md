# SafeNew
SafeNew is wrapper class of **__new__**, and was built based on RAII principle.
You can use **C**'s raw pointers without worrying about memory leaks. You can simply deallocate SafeNew object as much as you want and without any worries.

**This is an example of using the ___template<typename T> SafeNew<T>__ object, which is exception-safe and also memory leak safe**
```C++
int main() {
SafeNew<A> _new;
SafeNew<double> _new1;

A* a = _new(A());
_new.dealloc();
_new.dealloc();

double* d = _new1(3.14);
_new1.dealloc();
_new1.dealloc();

return 0;
}
```
