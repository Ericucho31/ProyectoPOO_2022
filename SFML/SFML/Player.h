#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
#include <string>
#include <memory>
#include "Juego.h"
#include "Entidad.h"
#include "Bullets.h"

using namespace sf;
using std::vector;
using std::string;

class Player : 
	public Entidad
{
public:
	vector <Bullets> balas;
	SoundBuffer buffer;
	Sound disparo;
	Player(string id, Juego* juegoDondeProviene);
	void Moverse() override;
};
