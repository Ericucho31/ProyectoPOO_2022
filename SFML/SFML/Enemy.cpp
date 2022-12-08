#include "Enemy.h"

Enemy::Enemy(string id, Juego* juegoDondeProviene) : Entidad(id, juegoDondeProviene)
{
	this->juegoDondeProviene = juegoDondeProviene;
	this->textura = this->juegoDondeProviene->ListaTextura.find("enemy")->second;
	this->skin = this->juegoDondeProviene->ListaSprites.find("enemy")->second;
	this->skin.setScale(0.25, 0.25);
}

void Enemy::Moverse()
{

		int azar = rand() % 4;
		Vector2f vectPlayer = this->skin.getPosition();
		if (azar==0)
			this->skin.setPosition(vectPlayer.x - 5, vectPlayer.y);
		if (azar == 1)
			this->skin.setPosition(vectPlayer.x + 5, vectPlayer.y);
		if (azar == 2)
			this->skin.setPosition(vectPlayer.x, vectPlayer.y - 5);
		if (azar == 3)
			this->skin.setPosition(vectPlayer.x, vectPlayer.y + 5);
}
