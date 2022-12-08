#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Juego.h"
#include "Entidad.h"
#include "Player.h"
#include <iostream>
#include <memory>

using namespace sf;
using std::cout;
using std::shared_ptr;

int main()
{
	bool game_over = false;//solo se declara un bool

	Juego *jueguito= new Juego;

	Player j1("nave", jueguito);

	auto prueba = jueguito->ListaSprites.find("nave");
	
	while (!game_over)
	{
		prueba->second.setRotation(180);

		jueguito->ventana->draw(jueguito->ListaSprites.find("fondo")->second);
		jueguito->ventana->draw(prueba->second);

		j1.Moverse();

		jueguito->ventana->draw(j1.skin);
		jueguito->ventana->display();
		
	}
		

	return 0;
}
