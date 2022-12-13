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

void Colision_Balas(Player* j1, Enemy* e1);
void ColisionPlayer(Player* j1, Enemy* e1);
void Procesos();
void PowerUp(Player j1);

SoundBuffer buffer, buffer_golpe, buffer_pacman;

Sound efecto, golpe, pacman;

bool game_over = false;//solo se declara un bool


int main()
{
	Font arial;
	Text texto;
	texto.Regular;
	texto.setString("HP");
	texto.setFont(arial);
	srand(time(0));
	

	Juego *jueguito= new Juego;
	jueguito->ventana->draw(texto);
	Procesos();

	Player* j1= new Player("nave", jueguito);
	Enemy* e1 = new Enemy("enemy", jueguito);
	
	while (!game_over)
	{
		jueguito->ventana->draw(jueguito->ListaSprites.find("fondo")->second);
		
		PowerUp(*j1);
		j1->Procesar();
		e1->Procesar();
		
		ColisionPlayer(j1, e1);
		Colision_Balas(j1, e1);
		
		jueguito->ventana->display();
	}
	return 0;
}

void Colision_Balas(Player* j1, Enemy* e1)
{
	for (size_t i = 0; i < j1->balas.size(); i++)
	{
		if (j1->balas[i].s_bullet.getGlobalBounds().intersects(e1->skin.getGlobalBounds()))
		{
			j1->balas.erase(j1->balas.begin() + i);
			//if (e1->HP <= 0) //borrar el enemigou
			//{
				//e1->skin.
			//} else
			e1->hp--; //enemigo recibe daño
			efecto.play();
			if (e1->hp <= 0)
			{
				game_over = true;
			}
		}
	}
}

void ColisionPlayer(Player* j1, Enemy* e1)
{
	for (size_t i = 0; i < e1->balas.size(); i++)
	{
		if (e1->balas[i].s_bullet.getGlobalBounds().intersects(j1->skin.getGlobalBounds()))
		{ 
			e1->balas.erase(e1->balas.begin() + i);
			j1->hp -= 30;
			golpe.play();

			if (j1->hp <= 0)
			{
				j1->vidas--;
				j1->hp = 100;
				efecto.play();
			}
			if (j1->vidas<=0)
			{
				pacman.play();
				j1->vidas = 3;
				game_over = true;
			}
		}
	}
}

void Procesos()
{
	buffer.loadFromFile("Archivos/explosion.wav");
	efecto.setBuffer(buffer);

	buffer_golpe.loadFromFile("Archivos/GolpeNavePlayer.wav");
	golpe.setBuffer(buffer_golpe);

	buffer_pacman.loadFromFile("Archivos/pacman_death.wav");
	pacman.setBuffer(buffer_pacman);
}

void PowerUp(Player j1)
{
	j1.coolDown = 14;
}
