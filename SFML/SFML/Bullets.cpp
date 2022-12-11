#include "Bullets.h"

Bullets::Bullets(Sprite sprite_bulllet, Vector2f pos)
{
	

	this->s_bullet = sprite_bulllet;
	this->s_bullet.setPosition(95, 150); //Posicion temporal solamente para comparar tamaños
	this->s_bullet.setScale(0.5, 0.5);
	this->s_bullet.setPosition(pos);
	
}

