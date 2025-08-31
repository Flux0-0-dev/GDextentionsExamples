#include "bullet.h"
#include <godot_cpp/core/class_db.hpp>





void Bullet::_bind_methods(){

    ClassDB::bind_method(D_METHOD("update_position"), &Bullet::update_position);
    ClassDB::bind_method(D_METHOD("set_position", "new_pos"), &Bullet::set_position);
    ClassDB::bind_method(D_METHOD("get_position"), &Bullet::get_position);
    ClassDB::bind_method(D_METHOD("set_rotation","new_rot"), &Bullet::set_rotation);
    ClassDB::bind_method(D_METHOD("get_rotation"), &Bullet::get_rotation);
    ClassDB::bind_method(D_METHOD("set_texture","new_text"), &Bullet::set_texture);
    ClassDB::bind_method(D_METHOD("get_texture"), &Bullet::get_texture);
    ClassDB::bind_method(D_METHOD("set_transform2D", "new_transf"), &Bullet::set_transform2D);
    ClassDB::bind_method(D_METHOD("get_transform2D"), &Bullet::get_transform2D);
    ClassDB::bind_method(D_METHOD("set_updater","new_updater"), &Bullet::set_updater);
    ClassDB::bind_method(D_METHOD("get_updater"), &Bullet::get_updater);
    ClassDB::bind_method(D_METHOD("set_velocity", "new_vel"), &Bullet::set_velocity);
    ClassDB::bind_method(D_METHOD("get_velocity"), &Bullet::get_velocity);
    ClassDB::bind_method(D_METHOD("setup"), &Bullet::setup);
    ClassDB::bind_method(D_METHOD("set_trect", "new_trect"),&Bullet::set_trect);
    ClassDB::bind_method(D_METHOD("get_trect"), &Bullet::get_trect);
    ClassDB::bind_method(D_METHOD("set_age", "new_age"), &Bullet::set_age);
    ClassDB::bind_method(D_METHOD("get_age"), &Bullet::get_age);

}

void Bullet:: update_position(double delta){
    position += velocity;
    set_transform2D(Transform2D(rotation,position));
    rs->canvas_item_set_transform(rcanvas_item,bullet_transform);
    age -= delta;
}

void Bullet::setup(){
    rcanvas_item = rs->canvas_item_create();
    rs->canvas_item_set_parent(rcanvas_item,updater->get_canvas());
    rs->canvas_item_add_texture_rect(rcanvas_item,trect,bullet_texture->get_rid());
    rs->canvas_item_set_transform(rcanvas_item,bullet_transform);

    rcollision=ps->circle_shape_create();
    query_shape->set_shape_rid(rcollision);
    query_shape->set_transform(bullet_transform);
}


void Bullet::set_transform2D(Transform2D new_transf){
    bullet_transform=new_transf;
}
Transform2D Bullet::get_transform2D() const{
    return bullet_transform;
}

void Bullet:: set_position(Vector2 new_pos){
    position = new_pos;
}
Vector2 Bullet:: get_position() const{
    return position;
}

void Bullet::set_velocity(Vector2 new_vel){
    velocity=new_vel;
}

Vector2 Bullet::get_velocity()const{
    return velocity;
}

void Bullet:: set_rotation(float new_rot){
    rotation = new_rot;
}

float Bullet:: get_rotation() const{
    return rotation;
}

void Bullet::set_texture(Ref<Texture2D> new_text){
    bullet_texture = new_text;
}
Ref<Texture2D> Bullet::get_texture()const{
    return bullet_texture;
}


Node2D* Bullet::get_updater()const{
    return updater;
}

void Bullet::set_updater(Node2D* new_updater){
    updater=new_updater;
}

void Bullet::set_trect(Rect2 new_trect){
    trect=new_trect;
}

Rect2 Bullet::get_trect() const {
    return trect;
}

void Bullet::set_age(double new_age){
    age=new_age;
}

double Bullet::get_age() const {
    return age;
}


Bullet::Bullet(){

}

Bullet::~Bullet(){
    ps->free_rid(rcollision);
    rs->free_rid(rcanvas_item);
}