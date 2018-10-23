# the true typedef
with this library you can define new types, that tend not to differ from existing ones<br>
**UNALIAS only works outside functions**

### usage
    using new_int = UNALIAS(int);
    
    struct Foo {};
    using new_Foo = UNALIAS(Foo);

### The code for independent UNALIASes was posted by Potatoswatter on stackoverflow.com
[https://stackoverflow.com/questions/6166337/does-c-support-compile-time-counters](https://stackoverflow.com/questions/6166337/does-c-support-compile-time-counters)
