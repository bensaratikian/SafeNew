# SafeNew
SafeNew is wrapper class of new, and was built based on RAII
```
int main() {
    A* a = _new<A>(A());
    int* i = _new<int>(2);
    return 0;
}
```
