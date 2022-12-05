#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Juego.h"
#include <iostream>

using namespace sf;
using std::cout;
using std::shared_ptr;

int main()
{
	bool game_over = false;//solo se declara un bool

	Juego jueguito;

	jueguito.CrearNuevoSprite("planet.png", "fondo", 0, 0);
	jueguito.CrearNuevoSprite("nave.png", "nave", 400, 300);

	auto prueba = jueguito.ListaSprites.find("nave");
	
	while (!game_over)
	{
		prueba->second.setRotation(180);
		jueguito.DibujarSprite("fondo", 100, 100);
		jueguito.DibujarSprite("nave", 300, 300);

		jueguito.ventana->draw(prueba->second);
		jueguito.ventana->display();
		
	}
		

	return 0;
}
