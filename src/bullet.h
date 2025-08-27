#pragma once
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/classes/rendering_server.hpp>
#include <godot_cpp/classes/physics_server2d.hpp>
#include <godot_cpp/classes/physics_shape_query_parameters2d.hpp>



using namespace godot;



class Bullet:public RefCounted
{
    GDCLASS(Bullet,RefCounted);

    // for physics
    PhysicsServer2D *ps = PhysicsServer2D::get_singleton();
    RID rcollision;//  I'll just make every variable with the type RID start with an "'r"
    PhysicsShapeQueryParameters2D query_shape ;
    
    //for rendering
    RenderingServer *rs =RenderingServer::get_singleton();
    Ref<Texture2D> bullet_texture =nullptr;
    RID rcanvas_item ;
    
protected:
    static void _bind_methods();

public:
    // bullet parameters
    Vector2 position = Vector2();
    float rotation ;
    Vector2 velocity = Vector2();
    Transform2D bullet_transform = Transform2D();

    void update_position();

    void set_transform2D(Transform2D new_transf);
    Transform2D get_transform2D() const;

    void set_position(Vector2 new_pos);
    Vector2 get_position() const;

    void set_rotation(float new_rot);
    float get_rotation() const;

    void set_texture(Ref<Texture2D> new_text);
    Ref<Texture2D> get_texture();

    Bullet(Transform2D init_transform));
    ~Bullet();
};
