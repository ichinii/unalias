#the true typedef
with this library you can define new types, that tend not to differ from existing ones
**UNALIAS only works outside functions**

#Usage
    using new_int = UNALIAS(int);
    
    struct Foo {};
    using new_Foo = UNALIAS(Foo);
