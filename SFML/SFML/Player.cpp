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
