#include "player.h"
#include <math.h>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/input.hpp>

void Player::_bind_methods(){
    ClassDB::bind_method(D_METHOD("get_gravity"),&Player::get_gravity);
    ClassDB::bind_method(D_METHOD("get_jump_height"),&Player::get_jump_height);
    ClassDB::bind_method(D_METHOD("set_jump_height","value"),&Player::set_jump_height);
    ClassDB::bind_method(D_METHOD("get_jump_time_to_peak"),&Player::get_jump_time_to_peak);
    ClassDB::bind_method(D_METHOD("set_jump_time_to_peak","value"),&Player::set_jump_time_to_peak);
    ClassDB::bind_method(D_METHOD("get_jump_time_to_decend"),&Player::get_jump_time_to_decend);
    ClassDB::bind_method(D_METHOD("set_jump_time_to_decend","value"),&Player::set_jump_time_to_decend);
    ClassDB::bind_method(D_METHOD("get_acc"),&Player::get_acc);
    ClassDB::bind_method(D_METHOD("set_acc","value"),&Player::set_acc);
    ClassDB::bind_method(D_METHOD("get_max_speed"),&Player::get_max_speed);
    ClassDB::bind_method(D_METHOD("set_max_speed","value"),&Player::set_max_speed);
    
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT,"acc"),"set_acc","get_acc");
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT,"max_speed"),"set_max_speed","get_max_speed");
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT,"jump_height"),"set_jump_height","get_jump_height");
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT,"jump_time_to_peak"),"set_jump_time_to_peak","get_jump_time_to_peak");
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT,"jump_time_to_decend"),"set_jump_time_to_decend","get_jump_time_to_decend");
};

void Player::_ready(){
    jump_velocity = -((2*jump_height)/jump_time_to_peak);
    jump_gravity = -((-2*jump_height)/pow(jump_time_to_peak,2));
    fall_gravity = -((-2*jump_height)/pow(jump_time_to_decend,2));
};

void Player::_physics_process(double p_delta){
    if (!is_on_floor()){
        velocity.y += get_gravity()*p_delta;
    }
    Input *ipt = Input::get_singleton();
    if (ipt->is_action_just_pressed("jump") && is_on_floor()){
        velocity.y = 0;
        velocity.y = jump_velocity;
    }
    if (velocity.y<0 && !ipt->is_action_pressed("jump")){
        velocity.y = Math::lerp(velocity.y, 0.0f, 0.25f);
    }
    velocity.y = Math::clamp(velocity.y,-1000.0f,1000.0f);
    float direction=ipt->get_axis("left","right");
    velocity.x=Math::move_toward(velocity.x,max_speed*direction,acc);
    set_velocity(velocity);
    move_and_slide();
};


float Player::get_acc() const{
    return acc;
}
void Player::set_acc(float x){
    acc=x;
}


float Player::get_max_speed() const{
    return max_speed;
}
void Player::set_max_speed(float x){
    max_speed=x;
}


float Player:: get_gravity() const{
    if (velocity.y > 0){
        return fall_gravity;
    }return jump_gravity;
};


float Player::get_jump_height() const{
    return jump_height;
};
void Player::set_jump_height(float x){
    jump_height=x;
};


float Player::get_jump_time_to_peak() const{
    return jump_time_to_peak;
};
void Player::set_jump_time_to_peak(float x){
    jump_time_to_peak=x;
};


float Player::get_jump_time_to_decend() const{
    return jump_time_to_decend;

};
void Player::set_jump_time_to_decend(float x){
    jump_time_to_decend=x;
};


Player::Player(){
    return;
};