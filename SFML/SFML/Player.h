#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <string>
#include <memory>
#include "Juego.h"
#include "Entidad.h"
#include "Bullets.h"
#include "Enemy.h"

using namespace sf;
using std::vector;
using std::string;

class Player : 
	public Entidad
{
public:
	Player(string id, Juego* juegoDondeProviene);

	int vidas;
	int coolDown;
	vector <Bullets> balas;
	SoundBuffer buffer;
	Sound disparo;
	
	void Moverse() override;
	void Disparar();
	void RecibirDaño();
	void DibujarBalas();
	void Procesar() override;
};
