#include "Enemy.h"

Enemy::Enemy(string id, Juego* juegoDondeProviene) : Entidad(id, juegoDondeProviene)
{
	this->juegoDondeProviene = juegoDondeProviene;
	this->textura = this->juegoDondeProviene->ListaTextura.find("enemy")->second;
	this->skin = this->juegoDondeProviene->ListaSprites.find("enemy")->second;
	this->skin.setScale(0.2, 0.2);
	this->skin.setOrigin(skin.getLocalBounds().width / 2, skin.getLocalBounds().height/1.1);
	//coloca el origen (de donde saldran las balas), en el centro horizontal y casi al fondo del sprite
}

Enemy::~Enemy()
{
	
}

void Enemy::Moverse()
{
		int azar = rand() % 4;
		Vector2f vectPlayer = this->skin.getPosition();
		if (azar==0)
			this->skin.setPosition(vectPlayer.x - 10, vectPlayer.y);
		if (azar == 1)
			this->skin.setPosition(vectPlayer.x + 10, vectPlayer.y);
		if (azar == 2)
			this->skin.setPosition(vectPlayer.x, vectPlayer.y - 10);
		if (azar == 3)
			this->skin.setPosition(vectPlayer.x, vectPlayer.y + 10);
}

void Enemy::Disparar()
{
	int azar = rand() % 100;
	if (azar > 95)
	{
		this->balas.push_back(Bullets(juegoDondeProviene->ListaSprites.find("bala")->second, this->skin.getPosition()));
	
	}
	for (size_t i = 0; i < this->balas.size(); i++)
	{
		this->balas[i].s_bullet.move(0.f, 9.f);

		//Balas fueras de la ventana
		if (this->balas[i].s_bullet.getPosition().y > this->juegoDondeProviene->ventana->getSize().y) //Condicion que señala si la bala esta fuera del limite en x de la ventana
			this->balas.erase(this->balas.begin() + i);
	}

	for (size_t i = 0; i < this->balas.size(); i++)
	{
		juegoDondeProviene->ventana->draw(this->balas[i].s_bullet);
	}
}

void Enemy::Procesar()
{
	this->Moverse();
	this->Disparar();
	this->juegoDondeProviene->ventana->draw(this->skin);
}
