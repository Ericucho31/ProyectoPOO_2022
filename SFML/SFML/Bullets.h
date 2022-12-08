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


class Bullets
{
public:
	Sprite s_bullet; //s_bullet (s_ de sprite para diferenciarlo del constructor)
	Bullets(Texture* textura, Vector2f pos);

	~Bullets() {};
	//se necesita crear un constructor y destructor de las balas porque queremos que existan 
	//cuando estemos jugando y que ya no existan jugando choquen con los enemigos
};

