#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
#include <string>
#include <memory>
#include "Juego.h"

using namespace sf;
using std::cout;
using std::vector;
using std::map;
using std::string;

class Entidad
{
public:
	string id;
	int hp=0;
	std::shared_ptr <Texture> textura;
	Sprite skin;
	Juego* juegoDondeProviene=nullptr;

	Entidad(string id, Juego *juegoDondeProviene);
	virtual void Moverse() = 0;
};

