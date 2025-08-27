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
    ClassDB::bind_method(D_METHOD("set_transform2D","new_transf"), &Bullet::set_transform2D);
    ClassDB::bind_method(D_METHOD("get_transform2D"), &Bullet::get_transform2D);
    
}

void Bullet:: update_position(){
    position += velocity;
    set_transform2D(Transform2D(rotation,position));
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

void Bullet:: set_rotation(float new_rot){
    rotation = new_rot;
}

float Bullet:: get_rotation() const{
    return rotation;
}

void Bullet::set_texture(Ref<Texture2D> new_text){
    bullet_texture = new_text;
}
Ref<Texture2D> Bullet::get_texture(){
    return bullet_texture;
}

Bullet::Bullet(Transform2D init_transform){
    rcanvas_item= rs->canvas_item_create();
    rs->canvas_item_set_transform(rcanvas_item,init_transform);
}

Bullet::~Bullet(){
    ps->free_rid(rcollision);
    rs->free_rid(rcanvas_item);
}