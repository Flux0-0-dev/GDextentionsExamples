#pragma once
#include <godot_cpp/classes/ref_counted.hpp>

using namespace godot;


class MyCounter:public RefCounted{
    GDCLASS(MyCounter,RefCounted);
    int c_value ;
    protected:
    static void _bind_methods();
    public:
    void add(int v);
    void reset();
    int get_number();
    MyCounter();
};