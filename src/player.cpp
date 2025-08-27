#include "player.h"
#include <math.h>
#include <godot_cpp/core/class_db.hpp>





void Player::_bind_methods(){
    ClassDB::bind_method(D_METHOD("get_gravity"), &Player::get_gravity);
    ClassDB::bind_method(D_METHOD("get_jump_height"), &Player::get_jump_height);
    ClassDB::bind_method(D_METHOD("set_jump_height", "value"), &Player::set_jump_height);
    ClassDB::bind_method(D_METHOD("get_jump_time_to_peak"), &Player::get_jump_time_to_peak);
    ClassDB::bind_method(D_METHOD("set_jump_time_to_peak", "value") ,&Player::set_jump_time_to_peak);
    ClassDB::bind_method(D_METHOD("get_jump_time_to_decend"), &Player::get_jump_time_to_decend);
    ClassDB::bind_method(D_METHOD("set_jump_time_to_decend", "value"), &Player::set_jump_time_to_decend);
    ClassDB::bind_method(D_METHOD("get_acc"), &Player::get_acc);
    ClassDB::bind_method(D_METHOD("set_acc", "value"), &Player::set_acc);
    ClassDB::bind_method(D_METHOD("get_max_speed"), &Player::get_max_speed);
    ClassDB::bind_method(D_METHOD("set_max_speed", "value"), &Player::set_max_speed);
    ClassDB::bind_method(D_METHOD("get_jump_buffer_timer"), &Player::get_jump_buffer_timer);
    ClassDB::bind_method(D_METHOD("set_jump_buffer_timer", "t"), &Player::set_jump_buffer_timer);
    ClassDB::bind_method(D_METHOD("jump_buffer_handler"),&Player::jump_buffer_handler);
    ClassDB::bind_method(D_METHOD("get_cayote_timer"),&Player::get_cayote_timer);
    ClassDB::bind_method(D_METHOD("set_cayote_timer","t"),&Player::set_cayote_timer);
    ClassDB::bind_method(D_METHOD("cayote_handler"),&Player::cayote_handler);

    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "acc"), "set_acc", "get_acc");
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "max_speed"), "set_max_speed", "get_max_speed");
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "jump_height"), "set_jump_height", "get_jump_height");
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "jump_time_to_peak"), "set_jump_time_to_peak", "get_jump_time_to_peak");
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "jump_time_to_decend"), "set_jump_time_to_decend", "get_jump_time_to_decend");
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "jump_buffer_timer", PROPERTY_HINT_NODE_TYPE, "Timer"), "set_jump_buffer_timer", "get_jump_buffer_timer");
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT,"cayote_jump_timer", PROPERTY_HINT_NODE_TYPE, "Timer"),"set_cayote_timer","get_cayote_timer");
};

void Player::_ready(){

};

void Player::_physics_process(double p_delta){
    jump_buffer_handler();
    cayote_handler();
    if (!is_on_floor()){
        velocity.y += get_gravity()*p_delta;
    }else {
        velocity.y=0.0f; // there is a bug if you delete this line the player might fall faster than it should be some time
    }
    if (!jump_buffer_timer->is_stopped() && (is_on_floor() || !cayote_jump_timer->is_stopped())){
        jump_buffer_timer->stop();
        cayote_jump_timer->stop();
        has_cayote = false;
        velocity.y = 0.0f;
        velocity.y = jump_velocity;
    }
    if (velocity.y<0 && !ipt->is_action_pressed("jump")){
        velocity.y = Math::lerp(velocity.y, 0.0f, 0.25f);
    }
    velocity.y = Math::clamp(velocity.y,-1000.0f,1000.0f);
    float direction = ipt->get_axis("left","right");
    velocity.x = Math::move_toward(velocity.x,max_speed*direction,acc);
    set_velocity(velocity);
    move_and_slide();
};


float Player::get_acc() const{
    return acc;
}
void Player::set_acc(float x){
    acc = x;
}


float Player::get_max_speed() const{
    return max_speed;
}
void Player::set_max_speed(float x){
    max_speed = x;
}


float Player:: get_gravity() const{
    return (velocity.y<0) ? jump_gravity : fall_gravity;
};


float Player::get_jump_height() const{
    return jump_height;
};
void Player::set_jump_height(float x){
    jump_height = x;
};


float Player::get_jump_time_to_peak() const{
    return jump_time_to_peak;
};
void Player::set_jump_time_to_peak(float x){
    jump_time_to_peak = x;
};


float Player::get_jump_time_to_decend() const{
    return jump_time_to_decend;

};
void Player::set_jump_time_to_decend(float x){
    jump_time_to_decend=x;
};


Timer* Player::get_jump_buffer_timer() const {
    return jump_buffer_timer;
}
void Player::set_jump_buffer_timer(Timer* t){
    jump_buffer_timer = t;
}

void Player::jump_buffer_handler(){
    if (ipt->is_action_just_pressed("jump")){
        jump_buffer_timer->start();
    }
}

Timer* Player::get_cayote_timer()const{
    return cayote_jump_timer ;
}
void Player::set_cayote_timer(Timer* t){
    cayote_jump_timer=t;
}
void Player::cayote_handler(){
    if  (is_on_floor()){
        has_cayote=true;
    }if (!is_on_floor() and has_cayote){
        has_cayote=false;
        cayote_jump_timer->start();
    }
}


Player::Player(){
    jump_velocity = -((2*jump_height)/jump_time_to_peak);
    jump_gravity = -((-2*jump_height)/pow(jump_time_to_peak,2));
    fall_gravity = -((-2*jump_height)/pow(jump_time_to_decend,2));
};