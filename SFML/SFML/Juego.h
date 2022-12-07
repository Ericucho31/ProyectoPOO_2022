#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
#include <string>
#include <memory>


using namespace sf;
using std::cout;
using std::vector;
using std::map;
using std::string;

class Juego
{
protected:
	
	string id;
public:
	Juego();
	RenderWindow* ventana; ///dentro de esta librería, hay una clase de nombre RenderWindow
	map <string, std::shared_ptr <Texture>> ListaTextura; //Los sprites tienen un apuntador que se dirige a la 
	//textura de donde provienen. Por lo cual, si la textura se destruye o su direccion de memoria se altera
	//ocurren errores. Por eso de utiliza un vector de shared_ptr (no pueden ser apuntadores normales,
	//debido a que cuando se ingresan los datos al vector con "push_back", la localidad de la memoria
	//se altera)
	map <String,Sprite> ListaSprites;

	void CrearNuevoSprite(string NombreArchivo, string id, int x, int y);

	void DesplegarVentana();
	void DibujarSprite(String id, int x, int y);

	RenderWindow* GetVentana() { return ventana; };
};

