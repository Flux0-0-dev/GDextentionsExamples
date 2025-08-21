#include "counter.h"
#include <godot_cpp/core/class_db.hpp>


void MyCounter::_bind_methods(){
    ClassDB::bind_method(D_METHOD("add","value"),&MyCounter::add);
    ClassDB::bind_method(D_METHOD("reset"),&MyCounter::reset);
    ClassDB::bind_method(D_METHOD("get_number"),&MyCounter::get_number);
};

void MyCounter::add(int v){
    c_value+=v;
};
void MyCounter::reset(){
    c_value=0;

};
int MyCounter::get_number(){
    return c_value;
};
MyCounter::MyCounter(){
    c_value=0;
};