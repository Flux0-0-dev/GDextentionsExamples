#include "bullet_updater.h"
#include <godot_cpp/core/class_db.hpp>



void BulletUpdater::_bind_methods(){
    ClassDB::bind_method(D_METHOD("set_texture", "new_texture"), &BulletUpdater::set_texture);
    ClassDB::bind_method(D_METHOD("get_texture"), &BulletUpdater::get_texture);
    ClassDB::bind_method(D_METHOD("init_bullet"), &BulletUpdater::init_bullet);
    ClassDB::bind_method(D_METHOD("set_rect", "new_rect"), &BulletUpdater::set_rect);
    ClassDB::bind_method(D_METHOD("get_rect"), &BulletUpdater::get_rect);

    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "texture", PROPERTY_HINT_RESOURCE_TYPE, "Texture2D"), "set_texture", "get_texture");
    ADD_PROPERTY(PropertyInfo(Variant::RECT2, "texture_rect"),"set_rect","get_rect"); 
}

BulletUpdater::BulletUpdater(){
    rng->randomize();
}

void BulletUpdater::_ready(){
   // init_bullet();
}

void BulletUpdater::_physics_process(double p_delta) {
    init_bullet();
    update_bullets(p_delta);
}

void BulletUpdater::set_texture(Ref<Texture2D> new_texture){
    bullet_texture=new_texture;
}

Ref<Texture2D> BulletUpdater::get_texture(){
    return bullet_texture;
}

void BulletUpdater::init_bullet(){
    Ref<Bullet> new_bullet = memnew(Bullet);
    new_bullet->set_updater(this);
    new_bullet->set_position(get_global_position());
    new_bullet->set_rotation(get_global_rotation());
    new_bullet->set_transform2D(get_global_transform());
    new_bullet->set_velocity(Vector2(1.0f, 1.0f).rotated(rng->randf_range(-M_PI,M_PI)));
    new_bullet->set_texture(bullet_texture);
    new_bullet->set_trect(texture_rect);
    //new_bullet->set_age(0.1);
    new_bullet->setup();
    bullets.push_back(new_bullet);
}

void BulletUpdater::set_rect(Rect2 new_rect){
    texture_rect = new_rect;
}

Rect2 BulletUpdater::get_rect(){
    return texture_rect;
}

void BulletUpdater::update_bullets(double delta){
    bullets.remove_if([delta](Ref<Bullet>& bullet) {
        if (bullet->get_age() <= 0) {
            return true; 
        }
        bullet->update_position(delta);
        return false;
    });
    
}

BulletUpdater::~BulletUpdater(){

}
