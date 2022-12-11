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

void Colision_Balas(Player j1, Enemy e1);
void Procesos();

SoundBuffer buffer;

Sound efecto;


int main()
{
	srand(time(0));
	bool game_over = false;//solo se declara un bool

	Juego *jueguito= new Juego;
	Procesos();

	Player j1("nave", jueguito);
	Enemy e1("enemy", jueguito);

	jueguito->CrearNuevoSprite("Archivos/bullet.png", "bala", 95, 105);

	auto enemy = jueguito->ListaSprites.find("enemy")->second;
	
	while (!game_over)
	{


		jueguito->ventana->draw(jueguito->ListaSprites.find("fondo")->second);

		j1.Moverse();
		e1.Moverse();
		

		jueguito->ventana->draw(j1.skin);
		jueguito->ventana->draw(e1.skin);

		Colision_Balas(j1, e1);
		jueguito->ventana->display();
		
	}
		

	return 0;
}

void Colision_Balas(Player j1, Enemy e1)
{
	for (size_t i = 0; i < j1.balas.size(); i++)
	{
		if (j1.balas[i].s_bullet.getGlobalBounds().intersects(e1.skin.getGlobalBounds()))
		{
			efecto.play();
		}
	}
}

void Procesos()
{
	buffer.loadFromFile("Archivos/explosion.wav");
	efecto.setBuffer(buffer);
}
