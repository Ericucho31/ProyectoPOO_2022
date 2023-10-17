#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include "Juego.h"
#include "Entidad.h"
#include "Enemy.h"
#include "Player.h"

#include <memory>

using namespace sf;

void Colision_Balas(Player* j1, Enemy* e1);
void ColisionPlayer(Player* j1, Enemy* e1);
void HUD(Player* j1, Juego* e1);
void Procesos();

SoundBuffer buffer, buffer_golpe, buffer_pacman;
Sound efecto, golpe, pacman;
Music musica_fondo;
Font font; Text PhpText, vidas;

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
	musica_fondo.play();
	while (!game_over)
	{
		
		jueguito->ventana->draw(jueguito->ListaSprites.find("fondo")->second);
		
		j1->Procesar();
		e1->Procesar();
		
		ColisionPlayer(j1, e1);
		Colision_Balas(j1, e1);
		HUD(j1, jueguito);
		
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
				
				j1->vidas = 3;
				game_over = true;
			}
		}
	}
}

void HUD(Player* j1, Juego* juego)
{
	PhpText.setString("HP Player; " + std::to_string(j1->hp));
	vidas.setString("Vidas; " + std::to_string(j1->vidas));
	juego->ventana->draw(PhpText);
	juego->ventana->draw(vidas);
}

void Procesos()
{
	buffer.loadFromFile("Archivos/explosion.wav");
	efecto.setBuffer(buffer);
	efecto.setVolume(50);

	buffer_golpe.loadFromFile("Archivos/GolpeNavePlayer.wav");
	golpe.setBuffer(buffer_golpe);

	buffer_pacman.loadFromFile("Archivos/pacman_death.wav");
	pacman.setBuffer(buffer_pacman);

	musica_fondo.openFromFile("Archivos/musica.wav");

	font.loadFromFile("Archivos/space age.ttf");
	PhpText.setFont(font);
	PhpText.setCharacterSize(15);
	PhpText.setFillColor(Color::White);
	PhpText.setPosition(630, 15);

	vidas.setFont(font);
	vidas.setCharacterSize(16);
	vidas.setFillColor(Color::White);
	vidas.setPosition(630, 35);
	//comentario para que cambie el git
	vidas.setCharacterSize(26);
}
