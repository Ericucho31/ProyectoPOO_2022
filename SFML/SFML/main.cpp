#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include "Juego.h"
#include "Entidad.h"
#include "Enemy.h"
#include "Player.h"

#include <memory>

using namespace sf;
using std::cout;
using std::shared_ptr;

void Colision_Balas(Player j1, Enemy* e1);
void Procesos();
void PowerUp(Player j1);

SoundBuffer buffer;

Sound efecto;


int main()
{
	Font arial;
	Text texto;
	texto.Regular;
	texto.setString("HP");
	texto.setFont(arial);
	srand(time(0));
	bool game_over = false;//solo se declara un bool

	Juego *jueguito= new Juego;
	jueguito->ventana->draw(texto);
	Procesos();

	Player j1("nave", jueguito);
	Enemy* e1 = new Enemy("enemy", jueguito);
	
	while (!game_over)
	{
		jueguito->ventana->draw(jueguito->ListaSprites.find("fondo")->second);
		
		PowerUp(j1);
		j1.Procesar();
		e1->Procesar();
		

		Colision_Balas(j1, e1);
		
		jueguito->ventana->display();
		
	}
		

	return 0;
}

void Colision_Balas(Player j1, Enemy* e1)
{
	for (size_t i = 0; i < j1.balas.size(); i++)
	{
		if (j1.balas[i].s_bullet.getGlobalBounds().intersects(e1->skin.getGlobalBounds()))
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

void PowerUp(Player j1)
{
	j1.coolDown = 14;
}