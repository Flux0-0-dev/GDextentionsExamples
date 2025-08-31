#pragma once

#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/classes/rendering_server.hpp>
#include <godot_cpp/classes/physics_server2d.hpp>
#include <godot_cpp/classes/physics_shape_query_parameters2d.hpp>
#include <godot_cpp/classes/node2d.hpp>



using namespace godot;



class Bullet:public RefCounted
{
    GDCLASS(Bullet,RefCounted);

    Node2D* updater = nullptr;
    double age = 10.0;//age in seconds
    // for physics
    PhysicsServer2D *ps = PhysicsServer2D::get_singleton();
    RID rcollision;//  I'll just make every variable with the type RID start with an "'r"
    Ref<PhysicsShapeQueryParameters2D> query_shape = memnew(PhysicsShapeQueryParameters2D);
    
    //for rendering
    RenderingServer *rs =RenderingServer::get_singleton();
    Ref<Texture2D> bullet_texture = nullptr;
    Rect2 trect = Rect2();
    RID rcanvas_item ;
    
protected:
    static void _bind_methods();

public:
    // bullet parameters
    Vector2 position = Vector2();
    float rotation = 0;
    Vector2 velocity = Vector2();
    Transform2D bullet_transform = Transform2D();

    void update_position(double delta);
    void setup();

    void set_transform2D(Transform2D new_transf);
    Transform2D get_transform2D() const;

    void set_position(Vector2 new_pos);
    Vector2 get_position() const;

    void set_velocity(Vector2 new_vel);
    Vector2 get_velocity()const;

    void set_rotation(float new_rot);
    float get_rotation() const;

    void set_texture(Ref<Texture2D> new_text);
    Ref<Texture2D> get_texture() const;

    void set_updater(Node2D* new_updater);
    Node2D* get_updater() const;

    //  texture rect
    void set_trect(Rect2 new_trect);
    Rect2 get_trect() const ;

    void set_age(double new_age);
    double get_age() const ;
    
    Bullet();
    ~Bullet();
};
