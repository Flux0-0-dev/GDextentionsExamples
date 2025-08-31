#pragma once

#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/classes/random_number_generator.hpp>
#include "bullet.h"

using namespace godot;
using namespace std;

class BulletUpdater:public Node2D {
    GDCLASS(BulletUpdater,Node2D);

private : 
    Ref<Texture2D> bullet_texture = nullptr;
    Ref<RandomNumberGenerator> rng = memnew(RandomNumberGenerator);
    Rect2 texture_rect = Rect2();
    protected:
    static void _bind_methods();
public:

    list<Ref<Bullet>> bullets;

    virtual void _ready() override;
    virtual void _physics_process(double p_delta) override;
    
    void init_bullet();
    void update_bullets(double delta);

    void set_texture(Ref<Texture2D> new_texture);
    Ref<Texture2D> get_texture();

    void set_rect(Rect2 new_rect);
    Rect2 get_rect();

    BulletUpdater();
    ~BulletUpdater();
};