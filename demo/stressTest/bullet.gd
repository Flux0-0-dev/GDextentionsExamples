extends Node2D

const ICON :Texture2D= preload("res://icon.svg");

@onready var bult:Bullet=Bullet.new();

func _ready() -> void:
	bult.set_updater(self);
	bult.set_transform2D(global_transform);
	#print(bult.get_transform2D());
	bult.set_position(global_position);
	#print(bult.get_position());
	bult.set_rotation(global_rotation);
	#print(bult.get_rotation());
	bult.set_velocity(Vector2(10,10));
	#print(bult.get_velocity());
	bult.set_texture(ICON);
	#print(bult.get_texture());
	bult.set_trect(Rect2(64,64,128,128));
	bult.setup();

func _process(_delta: float) -> void:
	if bult:
		bult.update_position();


func _on_timer_timeout() -> void:
	bult=null;
