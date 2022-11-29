#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>

using namespace sf;
using std::cout;

int main()
{
	Music musica;
	musica.openFromFile("musica.wav");
	bool game_over = false;//solo se declara un bool
	RenderWindow* ventana; ///dentro de esta librería, hay una clase de nombre RenderWindow
	ventana= new RenderWindow(VideoMode(800, 600, 32), "Ejemplo");
	ventana->setFramerateLimit(60);//limite de fps de la ventana

	Texture textura1, textura2; //La textura es lo que va a leer el archivo
	Sprite fondo, navecita; //esa textura se va a introducir en un Sprite, y 
	//los sprites es lo que vamos a utilizar en el juego
	
	textura1.loadFromFile("planet.png");//lee la imagen de fondo
	fondo.setTexture(textura1);
	fondo.scale(1, 1);//esto es si lo quieres escalar

	textura2.loadFromFile("nave.png");
	navecita.setTexture(textura2);

	navecita.setPosition(400,300);//a navecita le asigna esos valores iniciales en donde se va a mostrar
	//que en este caso es el puro centro de la pantalla

	
	while (!game_over)
	{
		Vector2f vect;//vector de posiciones en x & y, que se utilizara para mover la nave
		vect = navecita.getPosition();//guarda la posicion actual de la navecita
		
		ventana->draw(fondo);//dibuja el fondo
		
		//si alguna de las flechas del mouse es presionada, aumenta los valores de x & y
		//cambiando la posicion de la nave
		if (Keyboard::isKeyPressed(Keyboard::Left))
			navecita.setPosition(vect.x -10, vect.y);
		if (Keyboard::isKeyPressed(Keyboard::Right))
			navecita.setPosition(vect.x + 10, vect.y);
		if (Keyboard::isKeyPressed(Keyboard::Up))
			navecita.setPosition(vect.x, vect.y - 10);
		if (Keyboard::isKeyPressed(Keyboard::Down))
			navecita.setPosition(vect.x, vect.y + 10);
		if (Keyboard::isKeyPressed(Keyboard::Space))
			musica.play();

		ventana->draw(navecita);//dibuja la navecita otra vez

		ventana->display();//actualiza lo que va a mostrar la ventana
	}
	return 0;
}
