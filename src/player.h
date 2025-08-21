#pragma once
#include <godot_cpp/classes/character_body2d.hpp>

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


    float get_gravity() const;
    Player();
};