#pragma once
#include <godot_cpp/classes/character_body2d.hpp>
#include <godot_cpp/classes/timer.hpp>
#include <godot_cpp/classes/input.hpp>


using namespace godot;


class Player : public CharacterBody2D{
    GDCLASS(Player,CharacterBody2D);
    float max_speed=200;
    float acc=25;


    float jump_height=48;
    float jump_time_to_peak=0.3;
    float jump_time_to_decend=0.2;


    float jump_velocity;
    float jump_gravity;
    float fall_gravity;

   

protected :
    static void _bind_methods();
public :    
    Vector2 velocity ;

    Timer* jump_buffer_timer=nullptr; // note: you have to make it a nullptr by default or else it would crash 
    Timer* cayote_jump_timer=nullptr;

    Input *ipt = Input::get_singleton();

    virtual void _physics_process(double p_delta) override;
    virtual void _ready() override;


    float get_acc() const;
    void set_acc(float x);

    float get_max_speed() const;
    void set_max_speed(float x);

    float get_jump_height() const;
    void set_jump_height(float x);


    float get_jump_time_to_peak() const;
    void set_jump_time_to_peak(float x);


    float get_jump_time_to_decend() const;
    void set_jump_time_to_decend(float x);

    Timer* get_jump_buffer_timer() const ;
    void set_jump_buffer_timer( Timer* t);
    void jump_buffer_handler();

    Timer* get_cayote_timer() const;
    bool has_cayote=true;
    void set_cayote_timer(Timer* t);
    void cayote_handler();

    float get_gravity() const;
    Player();
};