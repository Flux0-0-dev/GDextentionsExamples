extends Node

#this thing took me half of my day to learn
func _ready() -> void:
	var my_counter:=MyCounter.new();
	my_counter.add(1);
	my_counter.add(3);
	my_counter.reset();
	my_counter.add(7);
	print(my_counter.get_number());
