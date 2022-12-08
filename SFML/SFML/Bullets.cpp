#include "Bullets.h"

Bullets::Bullets(Texture* textura, Vector2f pos)
{
	this->s_bullet.setTexture(*textura);
	this->s_bullet.setPosition(95, 150); //Posicion temporal solamente para comparar tamaños
	this->s_bullet.setScale(0.5, 0.5);
	this->s_bullet.setPosition(pos);
}
