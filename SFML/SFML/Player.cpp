#pragma once
#include "Player.h"

Player::Player(string id, Juego* juegoDondeProviene) : Entidad(id, juegoDondeProviene)
{
	this->juegoDondeProviene = juegoDondeProviene;
	this->textura = this->juegoDondeProviene->ListaTextura.find("nave")->second;
	this->skin = this->juegoDondeProviene->ListaSprites.find("nave")->second;
}

void Player::Moverse()
{
	Vector2f vectPlayer = this->skin.getPosition();
	if (Keyboard::isKeyPressed(Keyboard::Left))
		this->skin.setPosition(vectPlayer.x - 10, vectPlayer.y);
	if (Keyboard::isKeyPressed(Keyboard::Right))
		this->skin.setPosition(vectPlayer.x + 10, vectPlayer.y);
	if (Keyboard::isKeyPressed(Keyboard::Up))
		this->skin.setPosition(vectPlayer.x, vectPlayer.y - 10);
	if (Keyboard::isKeyPressed(Keyboard::Down))
		this->skin.setPosition(vectPlayer.x, vectPlayer.y + 10);
}
