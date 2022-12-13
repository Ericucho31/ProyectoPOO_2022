#pragma once
#include "Player.h"

Player::Player(string id, Juego* juegoDondeProviene) : Entidad(id, juegoDondeProviene)
{
	
	this->juegoDondeProviene = juegoDondeProviene;
	this->textura = this->juegoDondeProviene->ListaTextura.find("nave")->second;
	this->skin = this->juegoDondeProviene->ListaSprites.find("nave")->second;
	this->skin.setOrigin(38, 0);
	this->hp = 100;
	this->vidas = 3;

	buffer.loadFromFile("Archivos/DisparoPlayer.wav");
	disparo.setBuffer(buffer);
}

void Player::Moverse()
{
	coolDown++; //Cada frame se actualiza ese valor
	if (this->skin.getPosition().x <= 0)
		this->skin.setPosition(0.f, this->skin.getPosition().y); //Colision hacia la izquierda
	//player1.naveplayer.getPosition().x nos da la posicion en X y si es menos que 0 hacemos que 
		// el sprit de la nave se dibuje apartir de la posicion 0 solamente


	if (this->skin.getPosition().x >= this->juegoDondeProviene->ventana->getSize().x - this->skin.getGlobalBounds().width) //Colision hacia la derecha
		this->skin.setPosition(this->juegoDondeProviene->ventana->getSize().x - this->skin.getGlobalBounds().width, this->skin.getPosition().y);

	// ventana->getSize().x - player1.naveplayer.getGlobalBounds().width == obtenemos el valor de la ventana en X y le restamos el el ancho 
	// de nuestro sprit para que dejarle suficiente margen para que pueda dibujarse completo.  

	if (this->skin.getPosition().y <= 0)
		this->skin.setPosition(this->skin.getPosition().x, 0.f); //Colision del limite superior

	if (this->skin.getPosition().y >= this->juegoDondeProviene-> ventana->getSize().y - this->skin.getGlobalBounds().height) //Colision del limite inferior
		this->skin.setPosition(this->skin.getPosition().x, this->juegoDondeProviene->ventana->getSize().y - this->skin.getGlobalBounds().height);

	//***************Movimiento de la nave del jugador*****************//
	Vector2f vectPlayer = this->skin.getPosition();
	if (Keyboard::isKeyPressed(Keyboard::Left))
		this->skin.setPosition(vectPlayer.x - 10, vectPlayer.y);
	if (Keyboard::isKeyPressed(Keyboard::Right))
		this->skin.setPosition(vectPlayer.x + 10, vectPlayer.y);
	if (Keyboard::isKeyPressed(Keyboard::Up))
		this->skin.setPosition(vectPlayer.x, vectPlayer.y - 10);
	if (Keyboard::isKeyPressed(Keyboard::Down))
		this->skin.setPosition(vectPlayer.x, vectPlayer.y + 10);
	if (Keyboard::isKeyPressed(Keyboard::Space) && coolDown>15)
	{
		this->Disparar();
	}
}

void Player::Disparar()
{
	//Cada vez que se presiona la tecla de espacio, se creara una bala, que se alamacenara en el vector
	this->balas.push_back(Bullets(juegoDondeProviene->ListaSprites.find("bala")->second, this->skin.getPosition()));
	this->disparo.play(); //y tambien sonará el boton de disparar
	coolDown = 0;
}

void Player::RecibirDaño()
{

}

void Player::DibujarBalas()
{
	for (size_t i = 0; i < this->balas.size(); i++)
	{
		this->balas[i].s_bullet.move(0.f, -25.f);

		//Balas fueras de la ventana
		if (this->balas[i].s_bullet.getPosition().y > this->juegoDondeProviene->ventana->getSize().y) //Condicion que señala si la bala esta fuera del limite en x de la ventana
			this->balas.erase(this->balas.begin() + i);
	}

	for (size_t i = 0; i < this->balas.size(); i++)
	{
		juegoDondeProviene->ventana->draw(this->balas[i].s_bullet);
	}
}
void Player::Procesar()
{
	this->Moverse();
	this->DibujarBalas();
	this->juegoDondeProviene->ventana->draw(this->skin);
}
/*
void Player::Animar()
{
	for (auto frame : animacion)
	{
		
		juegoDondeProviene->ventana->draw(frame);
	}
}
*/
