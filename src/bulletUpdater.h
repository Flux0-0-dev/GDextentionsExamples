#pragma once

#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/texture2d.hpp>

using namespace godot;

class BulletUpdater:public Node2D {
    GDCLASS(BulletUpdater,Node2D);

private : 
    Ref<Texture2D> bullet_texture = nullptr;
protected:
    static void _bind_methods();
public:
    virtual void _physics_process(double p_delta) override;
    void set_texture(Ref<Texture2D>new_texture);
};