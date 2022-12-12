#include "Juego.h"
#include <iostream>

using std::map;

Juego::Juego()
{
	ventana = new RenderWindow(VideoMode(800, 600, 32), "Ejemplo");
	ventana->setFramerateLimit(60);


	CrearNuevoSprite("Archivos/planet.png", "fondo", 0, 0);
	CrearNuevoSprite("Archivos/nave.png", "nave", 400, 300);
	CrearNuevoSprite("Archivos/enemy.png", "enemy", 200, 200);
	CrearNuevoSprite("Archivos/bullet.png", "bala", 95, 105);
}

void Juego::CrearNuevoSprite(string NombreArchivo, string id, int x, int y)
{
	std::shared_ptr<Texture> textura(new Texture()); //se crea el espacio dinamico para la textura
	textura->loadFromFile(NombreArchivo);//carga la imagen

	Sprite nuevoSprite;
	nuevoSprite.setTexture(*textura); //se le asigna la textura al sprite
	nuevoSprite.setPosition(x, y);// y tambien su posición

	this->ListaTextura.insert(std::make_pair(id, textura));//se agregan las texturas y los sprite a la estructura de la clase
	this->ListaSprites.insert(std::make_pair(id, nuevoSprite));
}

void Juego::DibujarSprite(String id, int x, int y)
{
	Vector2f pos_original; //guardamos la posicion original para revertir los cambios

	auto sprite = this->ListaSprites.find(id); //buscamos
	if (sprite!=ListaSprites.end())
	{
		pos_original = sprite->second.getPosition();

		sprite->second.setPosition(x, y);
		this->ventana->draw(sprite->second);

		sprite->second.setPosition(pos_original);
	}
	
}


void Juego::DesplegarVentana()
{
	for (auto& spritecito : ListaSprites)
	{
		this->ventana->draw(spritecito.second);//se dibujan todos los sprites del vector
	}
	this->ventana->display();
}
