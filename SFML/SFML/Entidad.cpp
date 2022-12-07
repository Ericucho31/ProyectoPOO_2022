#include "Entidad.h"

Entidad::Entidad(string id, Juego *juegoDondeProviene)
{
	this->hp = 100;
	this->id = id;
	this->juegoDondeProviene = juegoDondeProviene;
}