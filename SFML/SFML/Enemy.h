#pragma once
#include "Entidad.h"
class Enemy :
    public Entidad
{
public:
    Enemy(string id, Juego* juegoDondeProviene);
    void Moverse() override;
};

