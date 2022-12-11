#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Juego.h"
#include "Entidad.h"
#include "Enemy.h"
#include "Player.h"
#include <iostream>
#include <memory>

using namespace sf;
using std::cout;
using std::shared_ptr;

void Colision(Player j1, Enemy e1);

SoundBuffer buffer;

Sound efecto;


int main()
{
	srand(time(0));
	bool game_over = false;//solo se declara un bool

	buffer.loadFromFile("Archivos/DisparoPlayer.wav");
	efecto.setBuffer(buffer);

	Juego *jueguito= new Juego;

	Player j1("nave", jueguito);
	Enemy e1("enemy", jueguito);

	auto enemy = jueguito->ListaSprites.find("enemy")->second;
	
	while (!game_over)
	{

		jueguito->ventana->draw(jueguito->ListaSprites.find("fondo")->second);

		j1.Moverse();
		e1.Moverse();
		Colision(j1, e1);

		jueguito->ventana->draw(j1.skin);
		jueguito->ventana->draw(e1.skin);
		jueguito->ventana->display();
		
	}
		

	return 0;
}

void Colision(Player j1, Enemy e1)
{

	if (j1.skin.getGlobalBounds().intersects(e1.skin.getGlobalBounds()))
	{
		efecto.play();
	}

	
}
